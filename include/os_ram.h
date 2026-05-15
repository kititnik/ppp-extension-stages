#ifndef __os_ram__
#define __os_ram__

#include "operation_system.h"
#include "linux_os.h"
#include "windows_os.h"
#include "os_in_out.h"

typedef struct OSRam {
    int ram_mb;
} <> OSRam;

OperationSystem + <osRam: OSRam;>;

OSRam + <linuxOS: LinuxOS;>;
OSRam + <windowsOS: WindowsOS;>;

InputTag + <ram_linuxOS: void;>;
InputTag + <ram_windowsOS: void;>;

#endif // __os_ram__