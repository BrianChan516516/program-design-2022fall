//
//  main.c
//  11194 - Stairs Climbing
//
//  Created by Brian on 2022/11/3.
//

#include <stdio.h>

int climbSrairs(int x) {
    
    if((x==1)||(x==2)||(x==3)) return x;
    
    int s[45];
    
    s[0] = 0;
    s[1] = 1;
    s[2] = 2;
    
    for(int i=3; i<=x; i++) s[i] = s[i-1] + s[i-2];
    
    return s[x];
    
}

int main(void) {
    
    int N, X = 0;
    
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        scanf("%d", &X);
        printf("%d\n", climbSrairs(X));
    }
    
    return 0;
    
}
