#include <random>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cmath>  //para el valor absoluto abs

#include "message.h"       
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Population.h"           

using namespace std;


#define VERBOSE true

#define PRINT_TIMES(f) {\
	VTime timeleft = nextChange();\
	VTime elapsed  = msg.time() - lastChange();\
	VTime sigma    = elapsed + timeleft;\
	cout << f << "@" << msg.time() <<\
		" - timeleft: " << timeleft <<\
		" - elapsed: " << elapsed <<\
		" - sigma: " << sigma << endl;\
}

Population::Population( const string &name ) : 
	Atomic( name ),
	out(addOutputPort( "out" )),
	in(addInputPort( "in" )),
	age(100),
	university_studies(1),
	political_involvement(1),
	employment_status(1),
	economic_status(1),
	centrality(1),
	political_affinity(1),
	current_fake_belief(1),
	current_fake_attacked_party(1),
	current_fake_urgency(1),
	current_fake_credibility(1),
	current_fake_media_party(1)
{

	age = str2Real( ParallelMainSimulator::Instance().getParameter( description(), "age" ) );
	university_studies = str2Real( ParallelMainSimulator::Instance().getParameter( description(), "university_studies" ) );
	political_involvement = str2Real( ParallelMainSimulator::Instance().getParameter( description(), "political_involvement" ) );
	employment_status = str2Real( ParallelMainSimulator::Instance().getParameter( description(), "employment_status" ) );
	economic_status = str2Real( ParallelMainSimulator::Instance().getParameter( description(), "economic_status" ) );
	centrality = str2Real( ParallelMainSimulator::Instance().getParameter( description(), "centrality" ) );
}

Model &Population::initFunction()
{
	// [(!) Initialize common variables]
	this->elapsed  = VTime::Zero;
 	this->timeLeft = VTime::Inf;
 	this->sigma = VTime::Inf; // stays in active state until an external event occurs;
 	
 	// set next transition
 	holdIn( AtomicState::passive, this->sigma  ) ;
	return *this ;
}

Model &Population::externalFunction( const ExternalMessage &msg )
{
#if VERBOSE
	PRINT_TIMES("dext");
#endif

	//[(!) update common variables]	
	this->sigma    = nextChange();	
	this->elapsed  = msg.time()-lastChange();	
 	this->timeLeft = this->sigma - this->elapsed; 
		
	Tuple<Real> message = Tuple<Real>::from_value(msg.value());
	Real attacked_party = message[0];
	Real fake_belief;

	current_fake_attacked_party = message[0];
	current_fake_urgency = message[1];
	current_fake_credibility = message[2];
	current_fake_media_party = message[3];

	if(message.size() == 3) { //message received from media

		fake_belief = this.beliefInFakeFromMedia(message);

	} else { //message received from other population

		fake_belief = this.beliefInFakeFromPopulation(message);
	}

	int multiplicative_factor = attacked_party == 1 ? 1 : (-1); // para saber si restar o sumar -> acercarse al partido 0 o 1
	political_affinity = political_affinity + multiplicative_factor * fake_belief * 0.1; // con el 0.1 nos acercamos de a poco 

	if (political_affinity > 1) {
		political_affinity = 1;
	} else if (political_affinity < 0) {
		political_affinity = 0;
	}

	if(message.size() == 3) { //mismo if dos veces horror

		// Generamos una transición interna para enviar el mensaje a las redes
		holdIn( AtomicState::active, VTime::Zero );

	} else { //message received from other population

		holdIn( AtomicState::passive, this->sigma ); // Si no hay que volver a enviar nada hasta la proxima fake pasivamos
	}

	return *this ;

}

Model &Population::internalFunction( const InternalMessage &msg )
{
#if VERBOSE
	PRINT_TIMES("dint");
#endif
	
	//aca se deberia llamar a la outputFunction no?

	this->sigma = VTime::Inf; // stays in passive state until an external event occurs;
	holdIn( AtomicState::passive, this->sigma );
	return *this;
}

Model &Population::outputFunction( const CollectMessage &msg )
{
	current_fake_attacked_party(1),
	current_fake_urgency(1),
	current_fake_credibility(1),
	current_fake_media_party(1)

	Tuple<Real> out_value{  current_fake_attacked_party,
							current_fake_urgency,
							current_fake_credibility,
							current_fake_media_party,
							age,
							university_studies,
							political_involvement,
							employment_status,
							economic_status,
							centrality,
							current_fake_belief,
							political_affinity
						};
						
	sendOutput( msg.time(), out, out_value ) ;
	return *this ;
}

Real Population::beliefInFakeFromMedia( Tuple<Real> message )
{
		Real attacked_party = message[0];
		Real urgency = message[1];
		Real credibility = message[2];
		Real media_party = message[3]; // agregar

		Real belief =    (1 - abs(media_party - political_affinity)) * 0.125   + // cuanto mas valga abs es que mas diferencia de afinidades hay - > menos va a creer
					(1 - university_studies) * 0.125 +
					(1 - abs(economic_status - 0.5)) * 0.125 + // 0.5 porque si esta en un extremo va a tener de esta forma un valor mayor
					(1 - employment_status) * 0.125 +
					(1 - political_involvement) * 0.125 +
					abs(attacked_party - political_affinity) * 0.125 +
					urgency * 0.125 +
					credibility * 0.125;
		
		return belief; 

}

Real Population::beliefInFakeFromPopulation( Tuple<Real> message )
{
		Real attacked_party = message[0];
		Real urgency = message[1];
		Real credibility = message[2];
		Real media_party = message[3]; // agregar

		Real sender_age = message[4];
		Real sender_university_studies = message[5];
		Real sender_political_involvement = message[6];
		Real sender_employment_status = message[7];
		Real sender_economic_status = message[8];
		Real sender_centrality = message[9];
		Real sender_fake_belief = message[10];
		Real sender_political_affinity = message[11];

		Real shared_traits_proportion = 1 - ((abs(age - sender_age) + 
										abs(university_studies - sender_university_studies) + 
										abs(political_involvement - sender_political_involvement) +
										abs(employment_status - employment_status) +
										abs(economic_status - sender_economic_status)) / 5); // dividi por 5 porque cada termino puede valer entre 0 y 1

		Real belief =   sender_fake_belief * 0.25 +
						shared_traits_proportion * 0.25 +
						sender_centrality * 0.25 +
						(1 - abs(political_affinity - sender_political_affinity)) * 0.25;

		return belief; 
}
