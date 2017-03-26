#include "tree.h"

int main() {
    init();
    TreeNode *test = get_node(0);
    add_node(0);
    add_node(0);
    add_node(1);
    rightmost_child(1);
    rightmost_child(0);
    rightmost_child(3);
    delete_my_subtree(&test);
    printf("sons after delete: \n");
    print_my_subtree(test);
    return 0;
}