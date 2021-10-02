#include "pmodeladm.h"
#include "register.h"

#include "FakeNewsGenerator.h"
#include "Media.h"
#include "Population.h"

void register_atomics_on(ParallelModelAdmin &admin)
{
        admin.registerAtomic(NewAtomicFunction<FakeNewsGenerator>(), GEN_MODEL_NAME);
        admin.registerAtomic(NewAtomicFunction<Media>(), MEDIA_MODEL_NAME);
        admin.registerAtomic(NewAtomicFunction<Population>(), POP_MODEL_NAME);
        admin.registerAtomic(NewAtomicFunction<Population>(), SOCIALNET_MODEL_NAME);
}
