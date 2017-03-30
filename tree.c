#include "tree.h"

static int new_node_index = 1;

void add_node(int index) {
    TreeNode *branch = get_node(index);
    pushback_new_son(branch, new_node_index++);
    printf(OK_MESSAGE);
}

void rightmost_child(int index) {
    TreeNode *branch = get_node(index);
    printf("%d\n", branch->sons->right_guard->prev->index);
}

void delete_node(int index) {
    TreeNode *branch = get_node(index);
    TreeNode *left = branch->sons->left_guard;
    TreeNode *right = branch->sons->right_guard;
    if (left->next == right) {
        bond_nodes(branch->prev, branch->next);
    } else { //branch has sons
        bond_nodes(branch->prev, left->next);
        bond_nodes(right->prev, branch->next);
    }
    free_node(branch);
    decrement_number_of_nodes();
    null_node(index);
    printf(OK_MESSAGE);
}

void delete_subtree(int index) {
    delete_sons(get_node(index));
    delete_node(index);
}

void split_node(int index, int sons_index) {
    TreeNode *branch = get_node(index);
    TreeNode *son = get_node(sons_index);
    TreeNode *right_brother_of_son = son->next;
    TreeNode *new = new_tree_node(new_node_index++);
    TreeNode *new_left_guard = new->sons->left_guard;
    TreeNode *new_right_guard = new->sons->right_guard;

    new_left_guard->prev = new_right_guard->next = new;
    if (right_brother_of_son != branch->sons->right_guard) {
        bond_nodes(new_left_guard, right_brother_of_son);
        bond_nodes(branch->sons->right_guard->prev, new_right_guard);
    } else { //son is a last son of his parent
        bond_nodes(new_left_guard, new_right_guard);
    }

    bond_nodes(son, new);
    bond_nodes(new, branch->sons->right_guard);
    printf(OK_MESSAGE);
}

void clean_up() {
    TreeNode *branch = get_node(0);
    delete_sons(branch);
    free_node(branch);
}