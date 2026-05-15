#include "mac_os.h"
#include "linux_os.h"
#include "windows_os.h"
#include <stdio.h>

OperationSystem* macOS_create(int installed_apps, ProcessorType processor_type) {
    struct OperationSystem.macOS* os = create_spec(OperationSystem.macOS);
    os->installed_apps = installed_apps;
    os->@processor_type = processor_type;
    return (OperationSystem*)os;
}

void combination_info<OperationSystem.macOS* os1, OperationSystem.macOS* os2>(FILE* file) {
	fprintf(file, "First and second OSes are MacOS\n");
}

void combination_info<OperationSystem.linuxOS* os1, OperationSystem.macOS* os2>(FILE* file) {
	fprintf(file, "Linux is better than Mac\n");
}

void combination_info<OperationSystem.macOS* os1, OperationSystem.linuxOS* os2>(FILE* file) {
	fprintf(file, "Mac is first and linux is second\n");
}

void combination_info<OperationSystem.macOS* os1, OperationSystem.windowsOS* os2>(FILE* file) {
	fprintf(file, "Windows is behind MacOS\n");
}

void combination_info<OperationSystem.windowsOS* os1, OperationSystem.macOS* os2>(FILE* file) {
	fprintf(file, "Windows in front of MacOS\n");
}