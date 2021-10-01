#ifndef __SocialNetworksType_H
#define __SocialNetworksType_H

#include <random>
#include "atomic.h"  // class Atomic
#include "VTime.h"


#define ATOMIC_MODEL_NAME "SocialNetworksType"

class SocialNetworksType: public Atomic{
	public:
		SocialNetworksType( const string &name = ATOMIC_MODEL_NAME ) ;	 // Default constructor
		~SocialNetworksType();					// Destructor
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
};


#endif  
