#include "tree.h"

int main() {
    init();
    TreeNode *test = get_node(0);
    add_node(0);
    add_node(0);
    add_node(0);
    split_node(0, 1);
    print_my_subtree(test);
    delete_subtree(4);
    printf("sons after delete: \n");
    print_my_subtree(test);

    return 0;
}