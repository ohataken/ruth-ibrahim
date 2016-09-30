#include "evaluator.h"

void eval(FILE* file, struct command* command) {
    char buffer[4];

    if (strcmp(command->name, "save") == 0) {
        fseek(file, sizeof(int) * command->index, SEEK_SET);
        fwrite(&command->value, sizeof(int), 1, file);
        printf("wrote\n");
    } else if (strcmp(command->name, "load") == 0) {
        fseek(file, sizeof(int) * command->index, SEEK_SET);
        fread(buffer, sizeof(int), 1, file);
        printf("&d", atoi(buffer));
    } else {
        perror("unexpected command name\n");
    }
}
