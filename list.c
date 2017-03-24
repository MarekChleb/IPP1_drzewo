//
// Created by Marek on 2017-03-24.
//

#include "list.h"

void list_pushback(List* l, int i) {
    ListNode* dummy;
    dummy = (ListNode*) malloc(sizeof(ListNode));

    dummy->next = NULL;
    dummy->prev = l->last;
    dummy->parent = l;
    dummy->data = i;
    if (l->last) {
        l->last->next = dummy;
    }
    l->last = dummy;
    if (!l->first) {
        l->first = dummy;
    }
}

static void print_list(List *l) {
    ListNode* it = l->first;
    while (it) {
        printf("%d\n", it->data);
        it = it->next;
    }
}