//
//  function.h
//  12568 - Reverse Linked List ver 2
//
//  Created by Brian on 2023/1/6.
//

#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int data;
    struct _Node* next;
} Node;

void Push(Node** ptr_head, int x) {
    Node* a = (Node*)malloc(sizeof(Node));
    a->data = x;
    a->next = *ptr_head;
    *ptr_head = a;
}

void Pop(Node** ptr_head) {
    if(*ptr_head == NULL) return;
    Node* ptr = *ptr_head;
    *ptr_head = (*ptr_head)->next;
    free(ptr);
}

void Reverse_List(Node** ptr_head) {
    
    Node *new, *new_head = NULL, *tmp = NULL;

    while(*ptr_head != NULL) {
        
        tmp = *ptr_head;
        
        new = (Node*)malloc(sizeof(Node));
        new->data = tmp->data;
        new->next = new_head;
        new_head = new;
        *ptr_head = tmp->next;
        free(tmp);
    }
    *ptr_head = new_head;
}

#endif
