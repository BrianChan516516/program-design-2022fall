//
//  function.h
//  13077 - Ranking System
//
//  Created by Brian on 2023/1/8.
//

#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include "function.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int score;
    char* name;
} Node;

int compare(Node* a, Node* b) {
    if(a->score < b->score) return 1;
    if(a->score > b->score) return -1;
    if(strcmp(a->name,b->name)>0) return 1;//not sure why
    if(strcmp(a->name,b->name)<0) return -1;//not sure why
    return 0;
}

void Insert( Node** Table, int N, int score, char* name ) {
    
    Table[N] = (Node*)malloc(sizeof(Node));
    Table[N]->score = score;
    Table[N]->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(Table[N]->name,name);
    
    for(int i=N-1; i>=0; i--) { //注意
        if(compare(Table[i], Table[i+1])>0) {
            Node* tmp = Table[i];
            Table[i] = Table[i+1];
            Table[i+1] = tmp;
        } else break;
    }
}

void Delete( Node** Table, int N, char* name ) {
    for(int i=0; i<N; i++) {
        if(strcmp(Table[i]->name, name)==0) {
            free(Table[i]->name);
            free(Table[i]);
            for(int j=i; j<N-1; j++) { //注意
                Table[j] = Table[j+1];
            } Table[N-1] = NULL;
            return;
        }
    }
}

int* Top( Node** Table, int N, int x) {
    int *S = (int*)malloc(sizeof(int)*x);
    for(int i=0; i<x; i++) S[i] = i;
    return S;
}


#endif
