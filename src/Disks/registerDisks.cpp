#include "registerDisks.h"

#include "DiskFactory.h"

#include <Common/config.h>

namespace DB
{

void registerDiskLocal(DiskFactory & factory);
void registerDiskMemory(DiskFactory & factory);

#if USE_SSL
void registerDiskEncrypted(DiskFactory & factory);
#endif

void registerDisks()
{
    auto & factory = DiskFactory::instance();

    registerDiskLocal(factory);
    registerDiskMemory(factory);

#if USE_SSL
    registerDiskEncrypted(factory);
#endif
}

}
