//
//  main.c
//  13290 - Matching Strings
//
//  Created by Brian on 2022/10/11.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    
    int n, m;
    int match[100] = {0};
    char S1[100][1002] = {0};
    char S2[100][1002] = {0};
    
    scanf("%d %d",&n, &m);
    
    for(int i=0; i<n; i++) scanf("%s",S1[i]);
    
    for(int i=0; i<m; i++) {
        
        scanf("%s",S2[i]);
        
        for(int j=0; j<n; j++) {
            if(strcmp(S2[i],S1[j]) == 0){
                match[i] = 1;
                break;
            }
        }
    }
    
    for(int i=0; i<m; i++) {
        if(match[i] == 1) printf("Yes\n");
        else printf("No\n");
    }
    
    return 0;
}
