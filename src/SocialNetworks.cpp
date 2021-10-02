#include <random>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "message.h"       
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "SocialNetworks.h"           

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

::SocialNetworks( const string &name ) : 
	Atomic( name ),
	out(addOutputPort( "out" )),
	in(addInputPort( "in" )),
	message() // esto es legal o habria que guardar todos los campos del mensaje por separado?
{
}

Model &SocialNetworks::initFunction()
{
	// [(!) Initialize common variables]
	this->elapsed  = VTime::Zero;
 	this->timeLeft = VTime::Inf;
 	this->sigma = VTime::Inf; // stays in active state until an external event occurs;
 	
 	// set next transition
 	holdIn( AtomicState::passive, this->sigma  ) ;
	return *this ;
}

Model &SocialNetworks::externalFunction( const ExternalMessage &msg )
{
#if VERBOSE
	PRINT_TIMES("dext");
#endif
	//[(!) update common variables]	
	this->sigma    = nextChange();	
	this->elapsed  = msg.time()-lastChange();	
 	this->timeLeft = this->sigma - this->elapsed; 
	
	message = Tuple<Real>::from_value(msg.value());

	// Generamos una transición interna.
	holdIn( AtomicState::active, VTime::Zero );
	
	return *this ;

}

Model &SocialNetworks::internalFunction( const InternalMessage &msg )
{
#if VERBOSE
	PRINT_TIMES("dint");
#endif
	this->sigma = VTime::Inf; // stays in passive state until an external event occurs;
	holdIn( AtomicState::passive, this->sigma );
	return *this;
}

Model &SocialNetworks::outputFunction( const CollectMessage &msg )
{
	sendOutput( msg.time(), out, message ) ;
	return *this ;
}
