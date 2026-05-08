#ifndef __linux_os__
#define __linux_os__

#include "operation_system.h"

typedef struct LinuxOS {
    int installed_version;
} LinuxOS;

OperationSystem + <linuxOS: LinuxOS;>;

OperationSystem* linux_create(int installed_apps, int installed_version);

#endif // __linux_os__