#ifndef __windows_os__
#define __windows_os__

#include "operation_system.h"

typedef struct WindowsOS {
    int release_year;
} WindowsOS;

OperationSystem + <windowsOS: WindowsOS;>;

OperationSystem* windows_create(int installed_apps, int release_year);

#endif // __windows_os__