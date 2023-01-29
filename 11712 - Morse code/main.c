//
//  main.c
//  11712 - Morse code
//
//  Created by Brian on 2022/12/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_morse(char* morse) {
    if(strcmp(morse,"*_") == 0) printf("A");
    else if(strcmp(morse,"_***") == 0) printf("B");
    else if(strcmp(morse,"_*_*") == 0) printf("C");
    else if(strcmp(morse,"_**") == 0) printf("D");
    else if(strcmp(morse,"*") == 0) printf("E");
    else if(strcmp(morse,"**_*") == 0) printf("F");
    else if(strcmp(morse,"__*") == 0) printf("G");
    else if(strcmp(morse,"****") == 0) printf("H");
    else if(strcmp(morse,"**") == 0) printf("I");
    else if(strcmp(morse,"*___") == 0) printf("J");
    else if(strcmp(morse,"_*_") == 0) printf("K");
    else if(strcmp(morse,"*_**") == 0) printf("L");
    else if(strcmp(morse,"__") == 0) printf("M");
    else if(strcmp(morse,"_*") == 0) printf("N");
    else if(strcmp(morse,"___") == 0) printf("O");
    else if(strcmp(morse,"*__*") == 0) printf("P");
    else if(strcmp(morse,"__*_") == 0) printf("Q");
    else if(strcmp(morse,"*_*") == 0) printf("R");
    else if(strcmp(morse,"***") == 0) printf("S");
    else if(strcmp(morse,"_") == 0) printf("T");
    else if(strcmp(morse,"**_") == 0) printf("U");
    else if(strcmp(morse,"***_") == 0) printf("V");
    else if(strcmp(morse,"*__") == 0) printf("W");
    else if(strcmp(morse,"_**_") == 0) printf("X");
    else if(strcmp(morse,"_*__") == 0) printf("Y");
    else if(strcmp(morse,"__**") == 0) printf("Z");
    //else printf("ERROR morse code : %s !\n",morse);
}

int main(void) {
    
    int N = 0, i=0, j=0;
    char in[1000] = {0};
    char morse[5] = {0};
    
    for(int k =0; k<5; k++) morse[k] = 0;//BUG(2/6)
    for(int k =0; k<1000; k++) in[k] = 0;
    
    scanf("%d\n",&N);
    
    for(int k=0; k<N; k++) scanf("%c",&in[k]);
    
    while(i<N) {
        if(in[i] == '=' && in[i+1] != '=') {
            //short signal "="
            morse[j++] = '*';
            i = i+1;
        } else if(in[i] == '=' && in[i+1] == '=' && in[i+2] == '=' && in[i+3] != '=') {
            //long signal "==="
            morse[j++] = '_';
            i = i+3;
        } else if(in[i] == '.' && in[i+1] != '.') {
            //single dot
            i = i+1;
        } else if((in[i] == '.') && (in[i+1] == '.') && (in[i+2] == '.')) {
            //seperate letter or words
            print_morse(morse);
            i = i+3;
           if((in[i] == '.')&&(in[i+1]=='.')&&(in[i+2]=='.')&&(in[i+3]=='.')) {
                //seperate words ＊一開始的BUG可能出在這邊
                i = i+4;
                printf(" ");
            }
            for(int k=0; k<5; k++) morse[k] = 0;
            j = 0;
        }
        
        if(i == N) {
            print_morse(morse);
            break;
        }
    }
    printf("\n");
    return 0;
}
