#include "pmodeladm.h"
#include "register.h"

#include "FakeNewsGenerator.h"
#include "Media.h"

void register_atomics_on(ParallelModelAdmin &admin)
{
        admin.registerAtomic(NewAtomicFunction<FakeNewsGenerator>(), GEN_MODEL_NAME);
        admin.registerAtomic(NewAtomicFunction<Media>(), MEDIA_MODEL_NAME);
}
