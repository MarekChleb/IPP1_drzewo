//
// Created by Marek on 2017-03-24.
//

#ifndef DRZEWO2_TREE_H

#define DRZEWO2_TREE_H

#include "list.h"

#define OK_COMMUNICATE "OK\n"

void add_node(int index);
void rightmost_child(int index);
void delete_node(int index);
void delete_subtree(int index);
void split_node(int index, int sons_index);

#endif //DRZEWO2_TREE_H
