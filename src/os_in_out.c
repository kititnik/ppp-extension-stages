#include "os_in_out.h"
#include <stdlib.h>

void OSIn<OperationSystem* os>(FILE* file) {} //= 0

void OSOut<OperationSystem* os>(FILE* file) {} //= 0

OperationSystem* OSCreateByTag<InputTag* tag>(int k) {
    printf("Unknown OS type for k = %d\n", k);
    exit(1);
}

OperationSystem* OSCreateAndIn(FILE* file) {
    int k = 0;
    if (fscanf(file, "%d", &k) == EOF) return NULL;

    int specSize = get_spec_size(InputTag);
    OperationSystem* sp = NULL;

    for (int i = 1; i < specSize; i++) {
        InputTag* tag = get_spec_ptr(InputTag, i);
        sp = OSCreateByTag<tag>(k);
        if (sp != NULL) break;
    }
    if (sp == NULL) {
        printf("Unknown OS type: %d\n", k);
        exit(1);
    }

    OSIn<sp>(file);
    return sp;
}