#include <stdio.h>
#include "command.h"

int main(void) {
    struct command command = read_command();
    printf("name %s\n", command.name);
    printf("index %d\n", command.index);
    printf("value %d\n", command.value);
    return 0;
}
