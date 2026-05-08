#include "windows_os.h"

OperationSystem* windows_create(int installed_apps, int release_year) {
    struct OperationSystem.windowsOS* os = create_spec(OperationSystem.windowsOS);
    os->installed_apps = installed_apps;
    os->@release_year = release_year;
    return (OperationSystem*)os;
}