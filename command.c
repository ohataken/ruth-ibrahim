#include "command.h"

char peekchar() {
    char c = getchar();
    ungetc(c, stdin);
    return c;
}

void consume_whitespace() {
    while (1) {
        char c = peekchar();

        if (isalnum(c)) {
            break;
        } else {
            getchar();
        }
    }
}

void read_command_name(struct command *command) {
    char buffer[8] = {0};
    int offset = 0;

    while (1) {
        char c = peekchar();

        if (isalpha(c)) {
            buffer[offset++] = c;
            getchar();
        } else {
            break;
        }
    }

    if (strcmp(buffer, "save") == 0) {
        command->name = SAVE;
    } else if (strcmp(buffer, "load") == 0) {
        command->name = LOAD;
    } else {
        perror("unexpected command name\n");
    }
}

int read_command_int() {
    int result = 0;

    while (1) {
        char c = peekchar();

        if (isnumber(c)) {
            getchar();
            result = 10 * result + c - '0';
        } else {
            break;
        }
    }

    return result;
}

void read_command_index(struct command *command) {
    command->index = read_command_int();
}

void read_command_value(struct command *command) {
    command->value = read_command_int();
}

struct command read_command() {
    struct command command;

    read_command_name(&command);
    consume_whitespace();

    read_command_index(&command);

    if (command.name == SAVE) {
        consume_whitespace();
        read_command_value(&command);
    }

    return command;
}
