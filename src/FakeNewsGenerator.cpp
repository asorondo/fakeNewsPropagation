/*******************************************************************
*
*  DESCRIPTION: class FakeNewsGenerator
*
*  AUTHOR: Amalia & Mariana & Matias
*
*  DATE: 30/9/2021
*
*******************************************************************/

/** include files **/
#include "FakeNewsGenerator.h"       // base header
#include "message.h"       // class InternalMessage 
#include "parsimu.h"      // class Simulator
#include "strutil.h"       // str2Value( ... )
#include <random>
#include "real.h"
#include "tuple_value.h"

using namespace std;

/*******************************************************************
* Function Name: Generator
* Description: constructor
********************************************************************/
FakeNewsGenerator::FakeNewsGenerator( const string &name )
	: Atomic( name ),
	  stop(addInputPort("stop")),
	  out( addOutputPort( "out" ) ),
	  dist_int(0,1),
	  dist_float(0.0,1.0),
	  rng(random_device()())
{

	string time( ParallelMainSimulator::Instance().getParameter( description(), "frequency" ));

	if( time != "" ) {
		preparationTime = time;
	}	
	else
	{
		MException e;
		e.addText( "No frequency parameter has been found for the model " + description() );
		MTHROW ( e );
	}
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &FakeNewsGenerator::initFunction()
{
	holdIn( AtomicState::active, preparationTime ) ;
	return *this ;
}

Model &FakeNewsGenerator::externalFunction(const ExternalMessage &msg)
{
	if(msg.port() == stop)
		passivate();

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &FakeNewsGenerator::internalFunction( const InternalMessage & )
{
	holdIn( AtomicState::active, preparationTime) ;
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &FakeNewsGenerator::outputFunction( const CollectMessage &msg )
{
	auto attacked_party = this->dist_int(this->rng); // 0 o 1
	auto urgency = this->dist_float(this->rng); // [0,1)
	auto credibility = this->dist_float(this->rng); // [0,1)
	Tuple<Real> out_value{Real(attacked_party), Real(urgency), Real(credibility)};
	sendOutput( msg.time(), out, out_value ) ;
	return *this ;
}

