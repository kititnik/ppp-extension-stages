#ifndef __windows_in_out__
#define __windows_in_out__

#include "os_in_out.h"
#include "windows_os.h"

InputTag + <windowsOS: void;>;

void OSIn<OperationSystem.windowsOS* os>(FILE* file);
void OSOut<OperationSystem.windowsOS* os>(FILE* file);
OperationSystem* OSCreateByTag<InputTag.windowsOS* tag>(int k);

#endif // __windows_in_out__
