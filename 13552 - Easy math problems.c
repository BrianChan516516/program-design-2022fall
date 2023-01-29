//
//  main.c
//  13552 - Easy math problems
//
//  Created by Brian on 2022/9/26.
//

#include <stdio.h>

int main(void) {
    
    double x, y, ans;
    char operator;
    
    scanf("%lf %c %lf", &x, &operator, &y);
    
    if(operator == '+') {
        ans = x+y;
    }else if(operator == '-') {
        ans = x-y;
    }else if(operator == '*') {
        ans = x*y;
    }else if(operator == '/') {
        ans = x/y;
    }else return 1;
    
    printf("%.3lf\n",ans);
    
    return 0;
}
