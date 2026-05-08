#include "linux_in_out.h"

void OSIn<OperationSystem.linuxOS* os>(FILE* file) {
    fscanf(file, "%d %d", &os->installed_apps, &os->@.installed_version);
}

void OSOut<OperationSystem.linuxOS* os>(FILE* file) {
    fprintf(file, "Linux OS: installed apps=%d, version=%d\n",
        os->installed_apps, os->@.installed_version);
}

OperationSystem* OSCreateByTag<InputTag.linuxOS* tag>(int k) {
    if (k == 0) return (OperationSystem*) create_spec(OperationSystem.linuxOS);
    return NULL;
}
