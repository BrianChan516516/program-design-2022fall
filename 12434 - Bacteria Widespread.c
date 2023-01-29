//
//  main.c
//  12434 - Bacteria Widespread
//
//  Created by Brian on 2022/10/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    
    int R, C, T;
    char room[105][105] = { };
    
    scanf("%d %d %d\n", &R, &C, &T);
    
    for(int i=0;i<R;i++) {
        for(int j=0; j<C; j++) {
            scanf("%c",&room[i][j]);
        }
        if(i!=R-1)scanf("\n");
    }
    
    for(int i=0;i<T;i++) {
        
        for(int i=0;i<R;i++) {
            for(int j=0; j<C; j++) {
                if(room[i][j] == 'F'){
                    if((room[i+1][j]!='#')&&(room[i+1][j]!='F'))room[i+1][j]='D';
                    if((room[i-1][j]!='#')&&(room[i-1][j]!='F'))room[i-1][j] = 'D';
                    if((room[i][j+1]!='#')&&(room[i][j+1]!='F'))room[i][j+1] = 'D';
                    if((room[i][j-1]!='#')&&(room[i][j-1]!='F'))room[i][j-1] = 'D';
                }
            }
            
        }
        
        //printf("\n");
        
        for(int i=0;i<R;i++) {
            for(int j=0; j<C; j++) {
                if(room[i][j] == 'D') room[i][j] = 'F';
            }
        }
        
    }
    
    //printf("\n");
    
    for(int i=0;i<R;i++) {
        for(int j=0; j<C; j++) {
            printf("%c",room[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
