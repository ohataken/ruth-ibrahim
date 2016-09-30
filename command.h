#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <ctype.h>

struct command {
    char name[4];
    int index;
    int value;
};

struct command read_command();

#endif
