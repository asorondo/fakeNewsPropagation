#include "pmodeladm.h"
#include "register.h"

#include "OfficialMediaType.h"


void register_atomics_on(ParallelModelAdmin &admin)
{
	admin.registerAtomic(NewAtomicFunction<OfficialMediaType>(), ATOMIC_MODEL_NAME);
}
