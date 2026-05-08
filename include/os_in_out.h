#ifndef __os_in_out__
#define __os_in_out__

#include "operation_system.h"
#include <stdio.h>

typedef struct InputTag {} <> InputTag;

OperationSystem* OSCreateByTag<InputTag* tag>(int k);
OperationSystem* OSCreateAndIn(FILE* ifst);
void OSIn<OperationSystem* os>(FILE* file);
void OSOut<OperationSystem* os>(FILE* file);

#endif // __os_in_out__