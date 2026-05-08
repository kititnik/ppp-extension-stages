#include "windows_in_out.h"

void OSIn<OperationSystem.windowsOS* os>(FILE* file) {
    fscanf(file, "%d %d", &os->installed_apps, &os->@.release_year);
}

void OSOut<OperationSystem.windowsOS *os>(FILE* file) {
    fprintf(file, "Windows OS: installed apps=%d, release year=%d\n",
        os->installed_apps, os->@.release_year);
}

OperationSystem* OSCreateByTag<InputTag.windowsOS* tag>(int k) {
    if (k == 1) return (OperationSystem*) create_spec(OperationSystem.windowsOS);
    return NULL;
}