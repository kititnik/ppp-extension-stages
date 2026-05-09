#include "mac_os.h"

OperationSystem* macOS_create(int installed_apps, ProcessorType processor_type) {
    struct OperationSystem.macOS* os = create_spec(OperationSystem.macOS);
    os->installed_apps = installed_apps;
    os->@processor_type = processor_type;
    return (OperationSystem*)os;
}