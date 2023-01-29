//
//  main.c
//  13293 - hijklmnop
//
//  Created by Brian on 2022/10/1.
//

#include <stdio.h>

int main(void) {
   
    char ary[15];
    char match[10];
    char ans[10];
    
    for(int i = 1; i<11; i++) ary[i] = getchar();
    for(int i = 1; i<5; i++) match[i] = getchar();
    
    for(int i = 1; i<5; i++) {
        if(('1' <= match[i]) && (match[i] <= '9')) { //number
            
            if(match[i]=='1') ans[i] = ary[1];
            else if(match[i]=='2') ans[i] = ary[2];
            else if(match[i]=='3') ans[i] = ary[3];
            else if(match[i]=='4') ans[i] = ary[4];
            else if(match[i]=='5') ans[i] = ary[5];
            else if(match[i]=='6') ans[i] = ary[6];
            else if(match[i]=='7') ans[i] = ary[7];
            else if(match[i]=='8') ans[i] = ary[8];
            else if(match[i]=='9') ans[i] = ary[9];
            
        }else if(('a' <= match[i]) && (match[i] <= 'z')){ //letter
            
            for(int j=1; j<11; j++)
                if(ary[j] == match[i]) {
                    if(j==1) ans[i] = '1';
                    if(j==2) ans[i] = '2';
                    if(j==3) ans[i] = '3';
                    if(j==4) ans[i] = '4';
                    if(j==5) ans[i] = '5';
                    if(j==6) ans[i] = '6';
                    if(j==7) ans[i] = '7';
                    if(j==8) ans[i] = '8';
                    if(j==9) ans[i] = '9';
                }
                    
                   
        }else {
            return 1;
        }
    }
    
    for(int i=1; i<5; i++) printf("%c",ans[i]);
    
    //printf("\n");
    
    return 0;
}
