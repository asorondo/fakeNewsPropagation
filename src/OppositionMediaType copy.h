#ifndef __OppositionMediaTypee_H
#define __OppositionMediaType_H

#include <random>
#include "atomic.h"  // class Atomic
#include "VTime.h"


#define ATOMIC_MODEL_NAME "OppositionMediaType"

class OppositionMediaType: public Atomic{
	public:
		OppositionMediaType( const string &name = ATOMIC_MODEL_NAME ) ;	 // Default constructor
		~OppositionMediaType();					// Destructor
		virtual string className() const {return ATOMIC_MODEL_NAME ;}
	
	protected:
		Model &initFunction();	
		Model &externalFunction( const ExternalMessage & );
		Model &internalFunction( const InternalMessage & );
		Model &outputFunction( const CollectMessage & );
	
	private:
		 const Port &in;	
		 Port &out ;   	// this is an output port named 'out'
	
		VTime sigma;
		
		// Time elapsed since the last state transition until now
		VTime elapsed;
		
		// Time remaining to complete the last programmed Lifetime
		VTime timeLeft;	

		typedef list<Value> ElementList ;
		ElementList elements ;
};	// class OppositionMediaType


#endif   
