#include "parse.h"

void parse_line() {
    char input[MAX_INPUT_SIZE];
    Command *to_do;

    gets(input);
    if (input[0] != '\0') {
        to_do = parse_command(input);
        do_a_command(to_do);
        free(to_do);
    }
}

Command* parse_command(char *input) {
    char *temp, *next;
    char command_name[MAX_COMMAND_NAME_SIZE];
    int value1 = -1, value2 = -1;
    Command* new_command;
    new_command = (Command*) malloc(sizeof(Command));

    switch (input[0]) {
        case 'A':
            sscanf(input, TYPE_1_INPUT_FORMAT, command_name, &value1);
            new_command->type = ADD_NODE_TYPE;
            break;

        case 'R':
            sscanf(input, TYPE_1_INPUT_FORMAT, command_name, &value1);
            new_command->type = RIGHTMOST_CHILD_TYPE;
            break;

        case 'D':
            sscanf(input, TYPE_1_INPUT_FORMAT, command_name, &value1);
            if (input[7] == 'N') {
                new_command->type = DELETE_NODE_TYPE;
            } else if (input[7] == 'S') {
                new_command->type = DELETE_SUBTREE_TYPE;
            }
            break;

        case 'S':
            sscanf(input, TYPE_2_INPUT_FORMAT, input, &value1, &value2);
            new_command->type = SPLIT_NODE_TYPE;
            break;

        default:
            break;
    }
    new_command->value1 = value1;
    new_command->value2 = value2;
    return new_command;
}

void do_a_command(Command *to_do) {
    switch (to_do->type) {
        case ADD_NODE_TYPE:
            add_node(to_do->value1);
            break;

        case RIGHTMOST_CHILD_TYPE:
            rightmost_child(to_do->value1);
            break;

        case DELETE_NODE_TYPE:
            delete_node(to_do->value1);
            break;

        case DELETE_SUBTREE_TYPE:
            delete_subtree(to_do->value1);
            break;

        case SPLIT_NODE_TYPE:
            split_node(to_do->value1, to_do->value2);
            break;

        default:
            break;
    }
}