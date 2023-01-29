//
//  main.c
//  13586 - Patrick's Calculator
//
//  Created by Brian on 2022/10/8.
//

#include <stdio.h>
#include <ctype.h>

int main(void) {
    
    char ch = '0', sum = '0', carry = '0';
    char A[150] = {'0'}, B[150] = {'0'}, ans[150] = {'0'};
    int i = 0, j = 0, k = 0, max = 0;
    //int max;
    
    while((ch = getchar()) != '\n') {
        if(isdigit(ch)) {
            A[i] = ch;
            i++;//','no need to i++
        }
    }
    
    while((ch = getchar()) != '\n') {
        if(isdigit(ch)) {
            B[j] = ch;
            j++;
        }
    }
    
    if(i>j)
        max = k = i;
    else
        max = k = j;
    
    i--; j--; k--;
    
    while(k >= 0) {
        
        if((i>=0)&&(j>=0)) sum = (A[i] - '0') + (B[j] - '0') + (carry - '0');
        else if(i<0) sum = (B[j] - '0') + (carry - '0');
        else if(j<0) sum = (A[i] - '0') + (carry - '0');
        
        carry = sum / 10;
        sum = sum % 10;
        
        ans[k] = '0' + sum;
        carry = '0' + carry;
        
        i--; j--; k--;
        
    }
    
    if(carry == '1') {
        for(i = max; i>0; i--) ans[i] = ans[i-1];
        ans[0] = '1';
        max++;
    }
    
    int n = max % 3;
    
    if(n == 0)n = 3;//special case
    
    for(int k=0; k<max; k++) {
        printf("%c",ans[k]);
        n--;
        if((n==0)&&(k<max-1)){
            printf(",");
            n = 3;
        }
    }
    
    printf("\n");
    
    return 0;
}
