#include <stdio.h>
#include "linux_os.h"
#include "windows_os.h"
#include "container.h"

void combination_info<OperationSystem* os1, OperationSystem* os2>(FILE* file) {} //= 0

void combination_info<OperationSystem.linuxOS* os1, OperationSystem.linuxOS* os2>(FILE* file) {
	fprintf(file, "First and second OSes are Linux\n");
}

void combination_info<OperationSystem.linuxOS* os1, OperationSystem.windowsOS* os2>(FILE* file) {
	fprintf(file, "Linux - Windows Combination\n");
}

void combination_info<OperationSystem.windowsOS* os1, OperationSystem.linuxOS* os2>(FILE* file) {
	fprintf(file, "Windows - Linux Combination\n");
}

void combination_info<OperationSystem.windowsOS* os1, OperationSystem.windowsOS* os2>(FILE* file) {
	fprintf(file, "First and second OSes are Windows\n");
}

void container_combination_info_out(FILE* file, struct ppVector.os* operation_systems) {
	int size = ppVector_size((ppVector*)operation_systems);
	for(int i = 0; i < size; i++) {
		OperationSystem* os1;
        ppVector_GET_VAL_INDEX(os1, (*operation_systems), i);
    	for(int j = 0; j < size; j++) {
			OperationSystem* os2;
        	ppVector_GET_VAL_INDEX(os2, (*operation_systems), j);
      		combination_info<os1, os2>(file);
    	}
  	}
}