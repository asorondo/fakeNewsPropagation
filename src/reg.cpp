#include "pmodeladm.h"
#include "register.h"

#include "FakeNewsGenerator.h"


void register_atomics_on(ParallelModelAdmin &admin)
{
        admin.registerAtomic(NewAtomicFunction<FakeNewsGenerator>(), ATOMIC_MODEL_NAME);
}
