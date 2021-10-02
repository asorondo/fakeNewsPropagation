#include "pmodeladm.h"
#include "register.h"

#include "FakeNewsGenerator.h"
#include "Media.h"
#include "Population.h"
#include "SocialNetworks.h"
#include "CoupledPopulation.h"


void register_atomics_on(ParallelModelAdmin &admin)
{
        admin.registerAtomic(NewAtomicFunction<FakeNewsGenerator>(), GEN_MODEL_NAME);
        admin.registerAtomic(NewAtomicFunction<Media>(), MEDIA_MODEL_NAME);
        admin.registerAtomic(NewAtomicFunction<Population>(), POP_MODEL_NAME);
        admin.registerAtomic(NewAtomicFunction<SocialNetworks>(), SOCIALNET_MODEL_NAME);
        admin.registerAtomic(NewAtomicFunction<CoupledPopulation>(), COUPLEDPOP_MODEL_NAME);
}
