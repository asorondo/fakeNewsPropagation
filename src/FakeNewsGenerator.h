/*******************************************************************
*
*  DESCRIPTION: class FakeNewsGenerator
*
*  AUTHOR: Amalia & Mariana & Matias
*
*  DATE: 30/9/2021
*
*******************************************************************/

#ifndef __FakeNewsGenerator_H
#define __FakeNewsGenerator_H

/** include files **/
#include "atomic.h"     // class Atomic
#include "except.h"     // class InvalidMessageException
#include <random>

#define GEN_MODEL_NAME "FakeNewsGenerator"

/** declarations **/
class FakeNewsGenerator : public Atomic
{
public:
	FakeNewsGenerator( const std::string &name = GEN_MODEL_NAME );				  // Default constructor

	virtual std::string className() const
		{return "FakeNewsGenerator";}

protected:
	Model &initFunction() ;

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const CollectMessage & );

private:
	const Port &stop;
	Port &out ;
	VTime preparationTime;

	std::uniform_int_distribution<int> dist_int; // 0 ò 1
	std::uniform_real_distribution<> dist_float; // [0,1)
    std::mt19937 rng;
			
};	// class FakeNewsGenerator


#endif   //__FakeNewsGenerator_H 
