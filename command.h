#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum {
    SAVE,
    LOAD,
};

struct command {
    int name;
    int index;
    int value;
};

struct command read_command();

#endif
