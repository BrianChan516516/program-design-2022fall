//
//  main.c
//  13672 - Fibonacci's soup
//
//  Created by Brian on 2022/11/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    long int S[5], n;
    long int f[55] = {0}, g[55] = {0};
    
    for(int i=0; i<4; i++) scanf("%ld",&S[i]);
    scanf("%ld",&n);
    
    f[0] = S[0];
    f[1] = S[1];
    g[0] = S[2];
    g[1] = S[3];
    
    for(int i=2;i<=50;i++) {
        
        if(i%2==0) f[i] = f[i-1] + g[i/2];
        else f[i] = f[i-1] + g[i-2];
        
        if(i%3==0) g[i] = g[i-1] + f[i/3];
        else g[i] = g[i-1] + f[i-2];
    }
    
    printf("%ld %ld\n",f[n],g[n]);
    
    //for(int i=0;i<=50;i++) printf("%d:%ld ",i,f[i]);
   
    return 0;
}
