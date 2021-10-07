/*******************************************************************
*
*  DESCRIPTION: class Media
*
*  AUTHOR: Amalia & Mariana & Matias
*
*  DATE: 30/9/2021
*
*******************************************************************/

#ifndef __Media_H
#define __Media_H

/** include files **/
#include "atomic.h"     // class Atomic
#include "except.h"     // class InvalidMessageException
#include <random>

#define MEDIA_MODEL_NAME "Media"

/** declarations **/
class Media : public Atomic
{
public:
	Media( const std::string &name = MEDIA_MODEL_NAME );				  // Default constructor

	virtual std::string className() const
		{return "Media";}

protected:
	Model &initFunction() ;

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const CollectMessage & );

private:
	const Port &in;	// this is an input port named 'in'
	Port &out ;   	// this is an output port named 'out'

	Real attacked_party;
	Real urgency;
	Real credibility;
	Real party; // lo casteo como Real pero en realidad es 0 o 1

	// Lifetime programmed since the last state transition to the next planned internal transition.
	VTime sigma;
	// Time elapsed since the last state transition until now
	VTime elapsed;
	// Time remaining to complete the last programmed Lifetime
	VTime timeLeft;	

		std::uniform_int_distribution<int> delay;
		std::uniform_real_distribution<> dist_float; // [0,1)
		std::mt19937 rng;

};	// class Media


#endif   //__Media_H 
