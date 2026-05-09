#include "os_inv_apps.h"

double calculate_inv_apps(OperationSystem* os) {
    if(os->installed_apps == 0) return 0;
    return (1/(double)os->installed_apps);
}