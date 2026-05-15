#ifndef __mac_in_out__
#define __mac_in_out__

#include "os_in_out.h"
#include "mac_os.h"

InputTag + <macOS: void;>;

void OSIn<OperationSystem.macOS* os>(FILE* file);
void OSOut<OperationSystem.macOS* os>(FILE* file);
OperationSystem* OSCreateByTag<InputTag.macOS* tag>(int k);

#endif // __mac_in_out__
