#ifndef __networkDelayType_H
#define __networkDelayType_H

#include <random>
#include "atomic.h"  // class Atomic
#include "VTime.h"


#define POP_MODEL_NAME "Population"

class Population: public Atomic{
	public:
		Population( const std::string &name = POP_MODEL_NAME ) ;	 

		virtual string className() const {return POP_MODEL_NAME ;}
	
	protected:
		Model &initFunction();	

		Model &externalFunction( const ExternalMessage & );
		
		Model &internalFunction( const InternalMessage & );

		Model &outputFunction( const CollectMessage & );
	
	private:
		 const Port &in;	
		 Port &out ;   

		Real population_id;
		Real age;
		Real university_studies;
		Real political_involvement;
		Real employment_status;		
		Real economic_status;
		Real centrality;
		Real political_affinity;

		Real current_fake_attacked_party;
		Real current_fake_urgency;
		Real current_fake_credibility;
		Real current_fake_media_party;
		Real current_fake_belief;

		bool is_message_received_from_media;
	
		VTime sigma;
		// Time elapsed since the last state transition until now
		VTime elapsed;
		// Time remaining to complete the last programmed Lifetime
		VTime timeLeft;	

		Real beliefInFakeFromPopulation(Tuple<Real>);
		Real beliefInFakeFromMedia(Tuple<Real>);
};	


#endif 
