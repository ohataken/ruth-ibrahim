#include <stdio.h>
#include "command.h"
#include "evaluator.h"

int main(void) {
    struct command command = read_command();
    FILE* file = fopen("./file.db", "w+");

    printf("name %s\n", command.name);
    printf("index %d\n", command.index);
    printf("value %d\n", command.value);

    eval(file, &command);

    return 0;
}
