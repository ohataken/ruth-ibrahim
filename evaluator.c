#include "evaluator.h"

void eval(FILE* file, struct command* command) {
    char buffer[4];

    switch (command->name) {
        case SAVE:
            fseek(file, sizeof(int) * command->index, SEEK_SET);
            fwrite(&command->value, sizeof(int), 1, file);
            printf("wrote\n");
            break;
        case LOAD:
            fseek(file, sizeof(int) * command->index, SEEK_SET);
            fread(buffer, sizeof(int), 1, file);
            printf("%d\n", buffer[0]);
            break;
        default:
            perror("unsupported command name\n");
    }
}
