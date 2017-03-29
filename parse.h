#ifndef DRZEWO2_PARSE_H
#define DRZEWO2_PARSE_H

#include <stdio.h>
#include <malloc.h>
#include "tree.h"

#define MAX_COMMAND_NAME_SIZE 20
#define MAX_INPUT_SIZE 200
#define ADD_NODE_TYPE 0
#define RIGHTMOST_CHILD_TYPE 1
#define DELETE_NODE_TYPE 2
#define DELETE_SUBTREE_TYPE 3
#define SPLIT_NODE_TYPE 4
#define TYPE_1_INPUT_FORMAT "%s %d"
#define TYPE_2_INPUT_FORMAT "%s %d %d"

typedef struct Command{
    int type;   /* 0 - add_node, 1 - rightmost_child, 2 - delete_node,
                 * 3 - delete_subtree, 4 - split_node
                 */
    int value1, value2;
} Command;

int parse_line();
Command* parse_command(char *input);
void do_a_command(Command *to_do);

#endif //DRZEWO2_PARSE_H
