//
//  main.c
//  13279 - Rearrange
//
//  Created by Brian on 2022/10/3.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    
    int N, M, a, b, buff;
    int arr[1002];
    int ans[1002];
    
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N; i++) {
        arr[i] = i + 1;
        ans[i] = i + 1;
    }
    
    for(int i=0; i<M; i++) {
        
        scanf("%d %d", &a, &b);
        
        buff = arr[a-1];
        
        arr[a-1] = arr[b-1];
        arr[b-1] = buff;
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i+1 == arr[j]) {
                ans[i] = j+1;
                break;
            }
        }
    }
    
    for(int i=0; i<N; i++) {
        if(i!=N-1) printf("%d ", ans[i]);
        else printf("%d", ans[i]);
    }
        
    
    printf("\n");
    
    return 0;
}
