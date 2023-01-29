//
//  main.c
//  13409 - Make sentence
//
//  Created by Brian on 2023/1/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu {
    int len;
    char* str;
} student;

student S[105];//students

void add(int x, char* s) {
    char *tmp = (char*)malloc(sizeof(char)*(S[x].len+1));
    strcpy(tmp, S[x].str);
    S[x].len += strlen(s);//add
    free(S[x].str);
    S[x].str = (char*)malloc(sizeof(char)*(S[x].len+1));
    strcpy(S[x].str, tmp);
    strcat(S[x].str, s);
    free(tmp);
}

void delete(int x, int k) {
    if(k>S[x].len) {
        S[x].len = 0;
        free(S[x].str);
        S[x].str = malloc(sizeof(char));
        S[x].str[0] = '\0';//add
    } else {
        S[x].len -= k;
        char* tmp = (char*)malloc(sizeof(char)*(S[x].len+1));
        strncpy(tmp, S[x].str, S[x].len);
        tmp[S[x].len] = '\0';//add
        free(S[x].str);
        //S[x].str = malloc(sizeof(char)*S[x].len);
        S[x].str = tmp;
        //free(tmp);
    }
}

void swap(int x, int y) {
    char* tmp;
    tmp = S[x].str;
    S[x].str = S[y].str;
    S[y].str = tmp;
    int len = S[x].len;
    S[x].len = S[y].len;
    S[y].len = len;
}

void longest(int N) {
    int max_len = S[1].len;
    int max_id = 1;
    
    for(int i=1; i<= N; i++) {
        if(S[i].len > max_len) {
            max_len = S[i].len;
            max_id = i;
        }
    }
    printf("%d %s\n",max_len,S[max_id].str);
}

void all(int N) {
    for(int i=1; i<=N; i++)
        printf("%s\n",S[i].str);
}

int main(void) {
    
    int N, M, x, k, y;
    char op[15];
    char s[105] = {'\0'};
    
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N+1; i++) { //students are from 1 to N
        S[i].len = 0;
        S[i].str = (char*)malloc(sizeof(char));
        S[i].str[0] = '\0';
    }
    
    for(int i=0; i<M; i++) {
        scanf("%s",op);
        if(strcmp(op,"add") == 0) {
            scanf("%d %s", &x, s);
            add(x,s);
        } else if(strcmp(op,"delete") == 0) {
            scanf("%d %d", &x, &k);
            delete(x,k);
        } else if(strcmp(op,"swap") == 0) {
            scanf("%d %d", &x, &y);
            swap(x,y);
        } else if(strcmp(op,"longest") == 0) {
            longest(N);
        } else if(strcmp(op,"all") == 0) {
            all(N);
        }
    }
    return 0;
}
