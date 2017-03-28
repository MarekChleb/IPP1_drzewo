//
// Created by Marek on 2017-03-24.
//

#include "tree.h"

static int new_node_index = 1;

void add_node(int index) {
    TreeNode *branch = get_node(index);
    pushback_new_son(branch, new_node_index++);
    printf("OK\n");
}

void rightmost_child(int index) {
    TreeNode *branch = get_node(index);
    if(branch->sons->last) {
        printf("%d", branch->sons->last->index);
    } else {
        printf("-1");
    }
}

void delete_node(int index) {
    TreeNode *branch = get_node(index);
    TreeNode *first_son = branch->sons->first;
    TreeNode *last_son = branch->sons->last;
    TreeNode *parent = branch->parent->node;//not NULL
    if(first_son) {
        first_son->parent->node = branch->parent->node;
        first_son->prev = branch->prev;
        if(branch->prev) {
            branch->prev->next = first_son;
        } else { //branch is the first son of his parent
            parent->sons->first = first_son;
        }
        last_son->next = branch->next;
        if(branch->next) {
            branch->next->prev = last_son;
        } else { //branch is the last son of his parent
            parent->sons->last = last_son;
        }
    } else { //branch has no first son, so therefore he has no sons
        if(branch->prev) {
            branch->prev->next = branch->next;
        } else { //branch is the first son of his parent
            parent->sons->first = branch->next;
        }
        if(branch->next) {
            branch->next->prev = branch->prev;
        } else { //branch is the last son of his parent
            parent->sons->last = branch->prev;
        }
    }

    null_node(index);
    free(branch);
    printf("OK\n")
}

void delete_subtree(int index) {
    delete_sons(get_node(index));
    delete_node(index);
    printf("OK\n");
}

void split_node(int index, int sons_index) {
    TreeNode* branch = get_node(index);
    TreeNode* son = get_node(sons_index);
    TreeNode* temp_last = branch->sons->last;



}

