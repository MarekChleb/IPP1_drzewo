#include <string.h>
#include "parse.h"

int main(int argc, char *argv[]) {
    init();
    if (argc == 2) {
        if (strcmp(argv[1], "-v") == 0) {
            while (parse_line()) {
                fprintf(stderr, "NODES: %d\n", get_current_number_of_nodes());
            }
        } else {
            fprintf(stderr, "ERROR");
            return 1;
        }
    } else {
        while (parse_line()) {
        }
    }
    clean_up();
    return 0;
}