#include <stdio.h>
#include "os_ram.h"

void OSRamOut<OSRam* os>(FILE* file, int ram_mb, int installed_apps) {} //= 0

void OSRamOut<OSRam.windowsOS* os>(FILE* file, int ram_mb, int installed_apps) {
    fprintf(file, "Windows OS: installed apps=%d, release year=%d, RAM amount=%d\n",
            installed_apps, os->@.release_year, ram_mb);
}

void OSRamOut<OSRam.linuxOS* os>(FILE* file, int ram_mb, int installed_apps) {
    fprintf(file, "Linux OS: installed apps=%d, version=%d, RAM amount=%d\n",
            installed_apps, os->@.installed_version, ram_mb);
}

void OSOut<OperationSystem.osRam* os>(FILE* file) {
    struct OSRam* os_ram = (struct OSRam*)&os->@;
    OSRamOut<os_ram>(file, os->@.ram_mb, os->installed_apps);
}
