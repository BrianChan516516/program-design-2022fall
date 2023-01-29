//
//  main.c
//  12134 - The Big Hammer Rise
//  Created by Brian on 2022/9/16.
//

#include <stdio.h>
#include <string.h>

int main(void) {
    
    int a1, a2;
    int b1, b2;
    
    int ans;
    
    scanf("%d.%d %d.%d", &a1, &a2, &b1, &b2);
    
    ans = ( a1*100 + a2 ) * ( b1*100 + b2 );
    
    printf("%d.%04d\n", ans/10000, ans%10000);
    
    return 0;
    
    /*if((a2/10 == 0)&&(b2/10 == 0)) {
        ans = ( a1*100 + a2*10 ) * ( b1*100 + b2*10 );
    } else if((a2/10 != 0)&&(b2/10 == 0)) {
        ans = ( a1*100 + a2 ) * ( b1*100 + b2*10 );
    } else if((a2/10 == 0)&&(b2/10 != 0)) {
        ans = ( a1*100 + a2*10 ) * ( b1*100 + b2 );
    }else ans = ( a1*100 + a2 ) * ( b1*100 + b2 );*/
}
