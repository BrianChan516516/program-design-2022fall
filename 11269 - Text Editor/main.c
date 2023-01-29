//
//  main.c
//  11269 - Text Editor
//
//  Created by Brian on 2022/12/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 500
char input[MAXSIZE+1];
int len;

typedef struct node {
    char c;
    struct node *f; //front
    struct node *r; //rear
} Node;

void add_node(Node *curr_node, char ch) {
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->c = ch;
    new_node->f = NULL;
    new_node->r = NULL;
    if(curr_node->r != NULL) {//不要粗心！！！
        new_node->r = curr_node->r;
        curr_node->r->f = new_node;
    }
    new_node->f = curr_node;
    curr_node->r = new_node;
}

void delete_node(Node* curr_node) {
    
    curr_node->f->r = curr_node->r;
    if(curr_node->r != NULL)
        curr_node->r->f = curr_node->f;
    
}

int main(void) {
    
    Node* head = (Node*)malloc(sizeof(Node));
    head->r = NULL;
    head->f = head;//important!!!
    Node* ptr = head;
    
    fgets(input, MAXSIZE, stdin);
    len = (int)strlen(input);
    
    for(int i=0; i<len; i++) {
        if(input[i] == '/') {
            if(input[i+1] == 'b') {
                delete_node(ptr);
                ptr = ptr->f;
                i+=9;
            } else if(input[i+1] == 'n') {
                add_node(ptr, '\n');
                ptr = ptr->r;
                i+=7;
            } else if(input[i+1] == 'l') {
                if(ptr->f != NULL)
                    ptr = ptr->f;
                i+=4;
            } else if(input[i+1] == 'r'){        /* /right */
                if(ptr->r != NULL)
                    ptr = ptr->r;
                i+=5;
            }
        } else {
            add_node(ptr, input[i]);
            ptr = ptr->r;
        }
    }
    
    head = head->r;
    while(head != NULL) {
        printf("%c", head->c);
        head = head->r;
    }
    
}
