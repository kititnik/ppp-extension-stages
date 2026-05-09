#include "mac_in_out.h"

void OSIn<OperationSystem.macOS* os>(FILE* file) {
    fscanf(file, "%d %d", &os->installed_apps, &os->@.processor_type);
}

void OSOut<OperationSystem.macOS* os>(FILE* file) {
    fprintf(file, "MacOS: installed apps=%d, processor type=", os->installed_apps);
    if(os->@.processor_type == ProcessorType_ARM) {
        fprintf(file, "ARM\n");
    }
    else if(os->@.processor_type == ProcessorType_X86) {
        fprintf(file, "X86\n");
    }
    else {
        fprintf(file, "ERROR\n");
    }
}

OperationSystem* OSCreateByTag<InputTag.macOS* tag>(int k) {
    if (k == 2) return (OperationSystem*) create_spec(OperationSystem.macOS);
    return NULL;
}
