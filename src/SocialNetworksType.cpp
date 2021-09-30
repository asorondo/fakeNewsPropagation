#include <random>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "message.h"       
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "SocialNetworksType.h"           

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

::SocialNetworksType( const string &name ) : 
	Atomic( name ),
	out(addOutputPort( "out" )),
	in(addInputPort( "in" ))
{
}

Model &SocialNetworksType::initFunction()
{
	return *this ;
}

Model &SocialNetworksType::externalFunction( const ExternalMessage &msg )
{
#if VERBOSE
	PRINT_TIMES("dext");
#endif
	return *this ;

}

Model &SocialNetworksType::internalFunction( const InternalMessage &msg )
{
#if VERBOSE
	PRINT_TIMES("dint");
#endif
}

Model &SocialNetworksType::outputFunction( const CollectMessage &msg )
{
	return *this ;
}

SocialNetworksType::~SocialNetworksType()
{
	//TODO: add destruction code here. Free distribution memory, etc. 
}
