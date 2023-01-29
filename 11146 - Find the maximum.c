//
//  main.c
//  11146 - Find the maximum
//
//  Created by Brian on 2022/10/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    int R, C;
    int val_max = -21474, val_min = 21474;
    int loc_max_i = 0, loc_max_j = 0, loc_min_i = 0,  loc_min_j = 0;
    int v_max;
    int l_max;
    int arr[12][12];
    
    scanf("%d %d",&R,&C);
    
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            
            scanf("%d",&arr[i][j]);
            
            if(arr[i][j] > val_max) {
                val_max = arr[i][j];//max of value
                loc_max_i = i;
                loc_max_j = j;
                //printf("Max :%d",val_max);//test
            }
            
            if(arr[i][j] < val_min) {
                val_min = arr[i][j];//min of value
                loc_min_i = i;
                loc_min_j = j;
                //printf("min :%d",val_max);//test
            }
            
        }
    }
    
    l_max = abs(loc_max_i - loc_min_i) + abs(loc_max_j - loc_min_j);
    v_max = abs(val_max - val_min);
        
    printf("%d %d", l_max, v_max);
    //printf("\n");//test
    
    return 0;
}
