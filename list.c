//
// Created by Marek on 2017-03-24.
//

#include "list.h"

static TreeNode* nodes[MAX_NUMBER_OF_TREE_NODES];

TreeNodesList* new_tree_nodes_list() {
    TreeNodesList *new_container;
    new_container = (TreeNodesList*) malloc(sizeof(TreeNodesList));
    new_container->first = new_container->last = NULL;

    return new_container;
}

TreeNode *new_tree_node(int index) {
    TreeNode *new_branch;
    TreeParentPointer *new_parent;
    new_branch = (TreeNode*) malloc(sizeof(TreeNode));
    new_parent = (TreeParentPointer*) malloc(sizeof(TreeParentPointer));
    new_parent->node = NULL;
    new_branch->index = index;
    new_branch->parent = new_parent;
    new_branch->prev = new_branch->next = NULL;
    new_branch->sons = new_tree_nodes_list();
    nodes[index] = new_branch;

    return new_branch;
}

void pushback_new_son(TreeNode *branch, int index) {
    TreeNode *new_son = new_tree_node(index);
    TreeNodesList* sons = branch->sons;
    new_son->parent->node = branch;
    if(sons->last) {
        new_son->prev = sons->last;
        sons->last->next = new_son;
    } else { //*branch has no sons.
        sons->first = new_son;
    }
    sons->last = new_son;
}

void print_sons(TreeNode *branch) {
    TreeNode *it = branch->sons->first;
    while(it) {
        printf("I'm in son %d\n", it->index);
        it = it->next;
    }
}

void print_my_subtree(TreeNode *branch) {
    if (branch) {
        TreeNode *it = branch->sons->first;
        printf("Im in %d:\n", branch->index);
        if (!it) {
            printf("I have no sons\n");
        }
        while (it) {
            printf("Entering my son %d\n", it->index);
            print_my_subtree(it);
            it = it->next;
        }
        printf("Quitting %d\n", branch->index);
    } else {
        printf("This subtree is empty\n");
    }
}

void delete_sons(TreeNode *branch) {
    TreeNode *it = branch->sons->first;
    while(it) {
        TreeNode *son_to_delete;
        son_to_delete = it;
        it = it->next;
        delete_sons(son_to_delete);
        free(son_to_delete);
    }
    branch->sons->first = branch->sons->last = NULL;
}

void delete_my_subtree(TreeNode **branch) {
    if((*branch)->parent) {
        if((*branch)->parent->node->sons->first == (*branch)) {
            (*branch)->parent->node->sons->first = NULL;
        }
        if((*branch)->parent->node->sons->last == (*branch)) {
            (*branch)->parent->node->sons->last = NULL;
        }

    }
    if((*branch)->next) {
        (*branch)->next->prev = (*branch)->prev;
    }
    if((*branch)->prev) {
        (*branch)->prev->next = (*branch)->next;
    }
    delete_sons(*branch);
    free(*branch);
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