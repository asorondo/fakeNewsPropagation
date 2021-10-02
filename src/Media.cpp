/*******************************************************************
*
*  DESCRIPTION: class Media
*
*  AUTHOR: Amalia & Mariana & Matias
*
*  DATE: 30/9/2021
*
*******************************************************************/

/** include files **/
#include "Media.h"       // base header
#include "message.h"       // class InternalMessage 
#include "parsimu.h"      // class Simulator
#include "strutil.h"       // str2Value( ... )
#include <random>
#include "real.h"
#include "tuple_value.h"

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

/*******************************************************************
* Function Name: Generator
* Description: constructor
********************************************************************/
Media::Media( const string &name )
	: Atomic( name ),
	  in(addInputPort("in")),
	  out( addOutputPort( "out" ) ),
	  party(0),
	  attacked_party(1),
	  urgency(1),
	  credibility(1)
{
	// El partido politico del medio
	party = str2Real( ParallelMainSimulator::Instance().getParameter( description(), "party" ) );
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Media::initFunction()
{
	// [(!) Initialize common variables]
	this->elapsed  = VTime::Zero;
 	this->timeLeft = VTime::Inf;
 	this->sigma = VTime::Inf; // stays in active state until an external event occurs;
 	
 	// set next transition
 	holdIn( AtomicState::passive, this->sigma  ) ;
	return *this ;
}

Model &Media::externalFunction( const ExternalMessage &msg )
{
#if VERBOSE
	PRINT_TIMES("dext");
#endif
	//[(!) update common variables]	
	this->sigma    = nextChange();	
	this->elapsed  = msg.time()-lastChange();	
 	this->timeLeft = this->sigma - this->elapsed; 
	
	attacked_party = Tuple<Real>::from_value(msg.value())[0];
	urgency = Tuple<Real>::from_value(msg.value())[1];
	credibility = Tuple<Real>::from_value(msg.value())[2];
	if(attacked_party!=party){
		// Partido enemigo, descreemos.
		credibility=0;
	}

	// Generamos una transición interna.
	holdIn( AtomicState::active, VTime::Zero );
	
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Media::internalFunction( const InternalMessage &msg )
{
	#if VERBOSE
		PRINT_TIMES("dint");
	#endif

	this->sigma = VTime::Inf; // stays in passive state until an external event occurs;
	holdIn( AtomicState::passive, this->sigma );
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Media::outputFunction( const CollectMessage &msg )
{
	Tuple<Real> out_value{attacked_party, urgency, credibility, party};
	sendOutput( msg.time(), out, out_value ) ;
	return *this ;
}
