//
//  main.c
//  12515 - Little Brick's Dream
//
//  Created by Brian on 2022/12/9.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int N, X, pos_num = 0;
int heights[10000001] = {0};
int comfort_lev[10000001] = {0};
int brick_pos[10000001] = {0};
//int first = 0;

int main(void) {
    
    scanf("%d %d", &N, &X);
    
    for(int i=0; i<N; i++)
        scanf("%d", &heights[i]);
    
    for(int i=0; i<N; i++) {
        
        for(int j=i-1; j>=0; j--) {
            
            if(heights[i] > heights[j]) {
                comfort_lev[i] = comfort_lev[i] + comfort_lev[j]+1;
                j = j - comfort_lev[j];
                //printf("i = %d, j = %d\n",i,j);
            } else if(heights[i] < heights[j])
                break;
        }
        //printf("%d ",comfort_lev[i]);
    }

    for(int i=0; i<N; i++) {
        if(comfort_lev[i] == X) {
            brick_pos[pos_num] = i + 1;
            pos_num ++;
        }
    }
    
    if(pos_num>0) {
        for(int i=0; i<pos_num; i++)
            if(i == pos_num-1)  printf("%d\n",brick_pos[i]);
            else printf("%d ",brick_pos[i]);
    } else
        printf("ouo\n");
    
    return 0;
}
