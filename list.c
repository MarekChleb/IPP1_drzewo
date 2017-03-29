//
// Created by Marek on 2017-03-24.
//

#include "list.h"

static int number_of_nodes = 0;
static TreeNode* nodes[MAX_NUMBER_OF_TREE_NODES];

TreeNodesList* new_tree_nodes_list(TreeNode* parent) {
    TreeNodesList *new_container;
    TreeNode *left, *right;
    new_container = (TreeNodesList*) malloc(sizeof(TreeNodesList));
    left = (TreeNode*) malloc(sizeof(TreeNode));
    right = (TreeNode*) malloc(sizeof(TreeNode));
    left->prev = right->next = parent;
    bond_nodes(left, right);
    left->index = INDEX_OF_LEFT_GUARD;
    right->index = INDEX_OF_RIGHT_GUARD;
    new_container->left_guard = left;
    new_container->right_guard = right;

    return new_container;
}

TreeNode *new_tree_node(int index) {
    TreeNode *new_branch;
    new_branch = (TreeNode*) malloc(sizeof(TreeNode));
    new_branch->index = index;
    new_branch->prev = new_branch->next = NULL;
    new_branch->sons = new_tree_nodes_list(new_branch);
    nodes[index] = new_branch;
    ++number_of_nodes;

    return new_branch;
}

void pushback_new_son(TreeNode *branch, int index) {
    TreeNode *new_son = new_tree_node(index);
    TreeNode* right = branch->sons->right_guard;
    bond_nodes(right->prev, new_son);
    bond_nodes(new_son, right);
}

void print_sons(TreeNode *branch) {
    TreeNode *it = branch->sons->left_guard->next;
    while(it != branch->sons->right_guard) {
        printf("I'm in son %d\n", it->index);
        it = it->next;
    }
}

void print_my_subtree(TreeNode *branch) {
    if (branch->sons->left_guard->next != branch->sons->right_guard) {
        TreeNode *it = branch->sons->left_guard->next;
        printf("Im in %d:\n", branch->index);
        while (it != branch->sons->right_guard) {
            printf("Entering my son %d\n", it->index);
            print_my_subtree(it);
            it = it->next;
        }
    } else {
        printf("This son is a leaf\n");
    }
    printf("Quitting %d\n", branch->index);
}

void delete_sons(TreeNode *branch) {
    TreeNode *it = branch->sons->left_guard->next;
    while(it != branch->sons->right_guard) {
        TreeNode *son_to_delete;
        son_to_delete = it;
        it = it->next;
        delete_sons(son_to_delete);
        null_node(son_to_delete->index);
        --number_of_nodes;
        free(son_to_delete);
    }
    bond_nodes(branch->sons->left_guard, branch->sons->right_guard);
}


void delete_my_subtree(TreeNode *branch) {
    bond_nodes(branch->prev, branch->next);
    delete_sons(branch);
    --number_of_nodes;
    free(branch);
}

void init() {
    TreeNode* root = new_tree_node(0);
}

TreeNode* get_node(int index) {
    return nodes[index];
}

void null_node(int index) {
    nodes[index] = NULL;
}

void bond_nodes(TreeNode *l, TreeNode *p) {
    l->next = p;
    p->prev = l;
}

int get_current_number_of_nodes() {
    return number_of_nodes;
}