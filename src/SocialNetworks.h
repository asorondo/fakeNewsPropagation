#ifndef __SocialNetworksType_H
#define __SocialNetworksType_H

#include <random>
#include "atomic.h"  // class Atomic
#include "VTime.h"


#define SOCIALNET_MODEL_NAME "SocialNetworks"

class SocialNetworks: public Atomic{
	public:
		SocialNetworks( const string &name = SOCIALNET_MODEL_NAME ) ;	 
		virtual string className() const {return SOCIALNET_MODEL_NAME ;}
	
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
