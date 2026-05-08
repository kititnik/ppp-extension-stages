#include "os_in_out.h"
#include "linux_in_out.h"
#include "windows_in_out.h"
#include "container.h"

void read_from_file(FILE* file, struct ppVector.os* operation_systems);
void write_to_file(FILE* file, struct ppVector.os* operation_systems);

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Wrong args! You should provide input and output files");
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    FILE* output_file = fopen(argv[2], "w");

    struct ppVector.os operation_systems;
    ppVector_INIT(operation_systems);

    read_from_file(input_file, &operation_systems);
    fclose(input_file);

    write_to_file(output_file, &operation_systems);
    fclose(output_file);
}

void read_from_file(FILE* file, struct ppVector.os* operation_systems) {
    OperationSystem* os;
    while ((os = OSCreateAndIn(file)) != NULL) {
        ppVector_PUSH_BACK((*operation_systems), os);
    }
}

void write_to_file(FILE* file, struct ppVector.os* operation_systems) {
    int size = ppVector_size((ppVector*)operation_systems);
    fprintf(file, "Container contains %d elements.\n", size);
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d: ", i);
        OperationSystem* os;
        ppVector_GET_VAL_INDEX(os, (*operation_systems), i);
        OSOut<os>(file);
    }
}