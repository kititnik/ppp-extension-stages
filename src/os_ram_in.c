#include "os_ram.h"
#include <stdio.h>

void OSRamIn<OSRam* os>(FILE* file) {} //= 0

void OSRamIn<OSRam.windowsOS* os>(FILE* file) {
    fscanf(file, "%d", &(os->@.release_year));
}

void OSRamIn<OSRam.linuxOS* os>(FILE* file) {
    fscanf(file, "%d", &(os->@.installed_version));
}

void OSIn<OperationSystem.osRam* os>(FILE* file) {
    fscanf(file, "%d", &os->installed_apps);
    struct OSRam* os_ram = (struct OSRam*)(&os->@);
    OSRamIn<os_ram>(file);
    fscanf(file, "%d", &(os->@ram_mb));
}

OperationSystem* OSCreateByTag<InputTag.ram_linuxOS *os>(int k) {
    if(k == 0) return create_spec(OperationSystem.osRam.linuxOS);
    return NULL;
}

OperationSystem* OSCreateByTag<InputTag.ram_windowsOS *os>(int k) {
    if(k == 1) return create_spec(OperationSystem.osRam.windowsOS);
    return NULL;
}
