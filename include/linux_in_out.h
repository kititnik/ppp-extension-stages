#ifndef __linux_in_out__
#define __linux_in_out__

#include "os_in_out.h"
#include "linux_os.h"

InputTag + <linuxOS: void;>;

void OSIn<OperationSystem.linuxOS* os>(FILE* file);
void OSOut<OperationSystem.linuxOS* os>(FILE* file);
OperationSystem* OSCreateByTag<InputTag.linuxOS* tag>(int k);

#endif // __linux_in_out__
