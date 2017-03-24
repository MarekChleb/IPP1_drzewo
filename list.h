//
// Created by Marek on 2017-03-24.
//

#ifndef DRZEWO2_LIST_H
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

#define DRZEWO2_LIST_H

#endif //DRZEWO2_LIST_H
