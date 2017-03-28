#include "tree.h"

int main() {
    init();
    TreeNode *test = get_node(0);
    add_node(0);
    add_node(0);
    add_node(0);
    add_node(2);
    add_node(2);
    print_my_subtree(test);
    delete_subtree(2);
    printf("sons after delete: \n");
    print_my_subtree(test);
    return 0;
}