#ifndef __mac_os__
#define __mac_os__

#include "operation_system.h"

typedef enum {
    ProcessorType_X86 = 0, 
    ProcessorType_ARM = 1
} ProcessorType;

typedef struct MacOS {
    ProcessorType processor_type;
} MacOS;

OperationSystem + <macOS: MacOS;>;

OperationSystem* macOS_create(int installed_apps, ProcessorType processor_type);

#endif // __mac_os__