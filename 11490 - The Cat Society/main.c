//
//  main.c
//  11490 - The Cat Society
//
//  Created by Brian on 2022/12/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10005

typedef struct cat {
    char name[50];
    int occu; //use int insted of array to save time
    int age;
} cat;

int compare(const void* a, const void* b) {
    cat A = *(cat*)a;
    cat B = *(cat*)b;
    if(A.occu == B.occu) {
        if(A.occu == 5 && B.occu == 5) {
            if(A.age > B.age) return 1;
            if(A.age < B.age) return -1;
            else return strcmp(A.name, B.name);
        } else {
            if(A.age > B.age) return -1;
            if(A.age < B.age) return 1;
            else return strcmp(A.name, B.name);
        }
    }
    else if(A.occu > B.occu) return 1;
    else if(A.occu < B.occu) return -1;
    else return 0;
}

int main(void) {
    
    int N, M;
    cat cats[MAX];
    
    while(~scanf("%d %d",&N, &M)){
        for(int i=0; i<N; i++) {
            
            char temp[50];
            
            scanf("%s %s %d",cats[i].name, temp, &cats[i].age);
            
            if(temp[0] == 'e') {
                cats[i].occu = 1;
            } else if(temp[0] == 'n') {
                cats[i].occu = 2;
            } else if(temp[0] == 'k') {
                cats[i].occu = 3;
            } else if(temp[0] == 'w') {
                cats[i].occu = 4;
            } else if(temp[0] == 'a') {
                cats[i].occu = 5;
            } else if(temp[0] == 'm') {
                cats[i].occu = 6;
            } else if(temp[0] == 'd') {
                cats[i].occu = 7;
            } else if(temp[0] == 'l') {
                cats[i].occu = 8;
            }
            
        }
        
        if(M>N) M=N; //cases when M is larger than N
        
        qsort(cats,N,sizeof(cat),compare);
        for(int i=0; i<M; i++) {
            printf("%s\n",cats[i].name);
        }
    }
    return 0;
}
