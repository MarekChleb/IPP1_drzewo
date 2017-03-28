/**
 *
 * static jak nie uzywamy poza plikiem
 *
 */

#ifndef DRZEWO2_LIST_H

#define DRZEWO2_LIST_H

#include <stdio.h>
#include <malloc.h>

#define MAX_NUMBER_OF_TREE_NODES 1000007

typedef struct TreeNode {
    int index;
    struct TreeParentPointer *parent;
    struct TreeNode *prev, *next;
    struct TreeNodesList *sons;
} TreeNode;
//dd
typedef struct TreeNodesList {
    TreeNode* first;
    TreeNode* last;
} TreeNodesList;

typedef struct TreeParentPointer {
    TreeNode *node;
} TreeParentPointer;

void init();
TreeNodesList* new_tree_nodes_list();
TreeNode* new_tree_node(int index);
void pushback_new_son(TreeNode *branch, int index);
void print_sons(TreeNode *branch);
void print_my_subtree(TreeNode *branch);
void delete_sons(TreeNode *branch);
void delete_my_subtree(TreeNode **branch);
TreeNode* get_node(int index);
void null_node(int index);

#endif //DRZEWO2_LIST_H
