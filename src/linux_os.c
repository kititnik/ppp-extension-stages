#include "linux_os.h"

OperationSystem* linux_create(int installed_apps, int installed_version) {
    struct OperationSystem.linuxOS* os = create_spec(OperationSystem.linuxOS);
    os->installed_apps = installed_apps;
    os->@installed_version = installed_version;
    return (OperationSystem*)os;
}