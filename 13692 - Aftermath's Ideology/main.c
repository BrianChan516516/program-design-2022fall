//
//  main.c
//  13692 - Aftermath's Ideology
//
//  Created by Brian on 2023/1/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct command {
    int type;
    char A, B, C;
    int id1, id2;
    char alpha[26];
} command;

char str[1000005];
char sub[1000005];

void swap(char* s, int a, int b) {
    char tmp;
    tmp = s[a];
    s[a] = s[b];
    s[b] = tmp;
}

int main(void) {
    
    int Q;
    
    for(int i=0; i<1000005; i++) sub[i] = -1;
    
    scanf("%s",str);
    scanf("%d",&Q);
    
    command* cmd = (command*)malloc(sizeof(command)*(Q+1));
    memset((void*)cmd, 0, sizeof(command)*(Q+1));
    
    for(int i=0; i<Q; i++) {
        scanf("%d",&cmd[i].type);
        if(cmd[i].type == 1) {
            scanf(" %c %c", &cmd[i].A, &cmd[i].B);
        } else if(cmd[i].type == 2) {
            scanf(" %d %c", &cmd[i].id1, &cmd[i].C);
        } else if(cmd[i].type == 3) {
            scanf(" %d %d", &cmd[i].id1, &cmd[i].id2);
        }
    }
    
    for(int i=0; i<26; i++)
        cmd[Q].alpha[i] = 'a' + i;
    
    for(int i=Q-1; i>=0; i--) {
        for(int j=0; j<26; j++)
            cmd[i].alpha[j] = cmd[i+1].alpha[j];
        if(cmd[i].type == 1) {
            cmd[i].alpha[cmd[i].A - 'a'] = cmd[i+1].alpha[cmd[i].B - 'a'];
        }
    }
    
    for(int i=0; i<Q; i++) {
        if(cmd[i].type == 2) {
            sub[cmd[i].id1] = cmd[i+1].alpha[cmd[i].C - 'a'];
        } else if(cmd[i].type == 3) {
            swap(sub, cmd[i].id1, cmd[i].id2);
            swap(str, cmd[i].id1, cmd[i].id2);
        }
    }
    
    int len = (int)strlen(str);
    
    for(int i=0; i<len ;i++) {
        if(sub[i] != -1) {
            printf("%c",sub[i]);
        } else {
            printf("%c",cmd[0].alpha[str[i] - 'a']);
        }
    } printf("\n");
    
    free(cmd);
    
    return 0;
}
