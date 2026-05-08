#include "linux_os"

OperationSystem* linux_create(int installed_apps, int installed_version) {
    struct OperationSystem.linux* os = create_spec(OperationSystem.linux);
    os->installed_apps = installed_apps;
    os->@installed_version = installed_version;
    return (OperationSystem*)os;
}