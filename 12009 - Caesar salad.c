//
//  main.c
//  12009 - Caesar salad
//
//  Created by Brian on 2022/10/1.
//

#include <stdio.h>

int main(void) {
    
    char a, b, c;
    int n;
    
    scanf("%c%c%c %d",&a, &b, &c, &n);
    
    
    
    if(n >= 0) {
        
        n = n%26;//make process much more faster
        
        a = 'A' + ((a - 'A') + n)%26;
        b = 'A' + ((b - 'A') + n)%26;
        c = 'A' + ((c - 'A') + n)%26;
        
    }else { //n<0
        
        n = 0 - n;//將n變成正數
        
        n = n%26;
        
        a = 'Z' - (n + ('Z' - a))%26;
        b = 'Z' - (n + ('Z' - b))%26;
        c = 'Z' - (n + ('Z' - c))%26;
        
    }
    
    printf("%c%c%c\n", a, b, c);
    
    return 0;    
}
