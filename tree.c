//
// Created by Marek on 2017-03-24.
//

#include "tree.h"

static int new_node_index = 1;

void add_node(int index) {
    TreeNode *branch = get_node(index);
    pushback_new_son(branch, new_node_index++);
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
    TreeNode *parent = branch->parent->node;
    if(first_son) {
        first_son->parent->node = branch->parent->node;
        first_son->prev = branch->prev;
        if(branch->prev) {
            branch->prev->next = first_son;
        }
        last_son->next = branch->next;
        if(branch->next) {
            branch->next->prev = last_son;
        }
    } else {
        if(branch->next) {
            branch->next->prev = branch->prev;
        } else {
            parent->sons->last = branch->prev;
        }
        if(branch->prev) {
            branch->prev->next = branch->next;
        } else {
            parent->sons->first = branch->next;
        }
    }
}

