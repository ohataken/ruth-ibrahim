#include <stdio.h>
#include "command.h"
#include "evaluator.h"

int main(void) {
    struct command command = read_command();
    FILE* file = fopen("./file.db", "r+");

    // printf("name %d\n", command.name);
    // printf("index %d\n", command.index);
    // printf("value %d\n", command.value);

    eval(file, &command);

    fclose(file);

    return 0;
}
