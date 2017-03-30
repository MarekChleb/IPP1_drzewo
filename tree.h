#ifndef DRZEWO2_TREE_H

#define DRZEWO2_TREE_H

#include "list.h"

#define OK_MESSAGE "OK\n"

void add_node(int index);

void rightmost_child(int index);

void delete_node(int index);

void delete_subtree(int index);

void split_node(int index, int sons_index);

void clean_up();

#endif //DRZEWO_TREE_H
