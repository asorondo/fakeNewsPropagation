#ifndef __CoupledPopulation_H
#define __CoupledPopulation_H

#include <random>
#include "atomic.h"  // class Atomic
#include "VTime.h"


#define COUPLEDPOP_MODEL_NAME "CoupledPopulation"

class CoupledPopulation: public Atomic{
	public:
		CoupledPopulation( const string &name = COUPLEDPOP_MODEL_NAME ) ;	 
		virtual string className() const {return COUPLEDPOP_MODEL_NAME ;}
	
	protected:
		Model &initFunction();	
		Model &externalFunction( const ExternalMessage & );
		Model &internalFunction( const InternalMessage & );
		Model &outputFunction( const CollectMessage & );
	
	private:
		 const Port &in;	
		 Port &out ;   	// this is an output port named 'out'

		Tuple<Real> message;
	
		VTime sigma;
		
		// Time elapsed since the last state transition until now
		VTime elapsed;
		
		// Time remaining to complete the last programmed Lifetime
		VTime timeLeft;	
};


#endif  
