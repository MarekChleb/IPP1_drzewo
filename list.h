/**
 *
 * static jak nie uzywamy poza plikiem
 *
 */

#ifndef DRZEWO2_LIST_H
#include <stdio.h>
#include <malloc.h>

typedef struct ListNode {
    int data;
    struct List* parent;
    struct ListNode* prev;
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* first;
    ListNode* last;
} List;

List new();
void list_pushback(List* l, int i);
void list_free(List* list);
size_t list_size(List* list); // wystarczy dodać do struktury List pole size_t count;
void list_insert(List* list, size_t index);
int list_get(List* list, size_t index);
void list_remove(List* list, size_t index);

#define DRZEWO2_LIST_H

#endif //DRZEWO2_LIST_H
