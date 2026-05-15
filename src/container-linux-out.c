#include <stdio.h>
#include "container.h"
#include "linux_os.h"

void OSOut<OperationSystem* s>(FILE* file);

void container_linux_only_out(FILE* file, struct ppVector.os* operation_systems) {
    struct OperationSystem.linuxOS linuxOS;
	int size = ppVector_size((ppVector*)operation_systems);
    for(int i = 0; i < size; i++) {
		OperationSystem* os;
        ppVector_GET_VAL_INDEX(os, (*operation_systems), i);
		if(spec_index_cmp(&linuxOS, os) >= 0) {
			OSOut<os>(file);
		}
    }
}
