#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdlib.h>
#include <string.h>

int solver(int **ptr, int *sum, char *s) {
    
    int len = (int)strlen(s);
    int count = 0, buff_count = 0;
    char buff[100000] = {' '};
    int check_point = 0;
    
    for(int i = 0; i<len; i++) {
        
        if(s[i]>='0' && s[i]<='9') {
            buff[buff_count] = s[i];
            if(buff_count == 0) check_point = i-1;
            buff_count++;
        }
        
        if((s[i-1]>='0'&&s[i-1]<='9') && (s[i]<'0'||s[i]>'9')) {
            
            *ptr[count] = (int)atoi(buff);
            
            if(s[check_point] == '-') {
                *ptr[count] = 0 -  *ptr[count];
            }
            
            for(int i=0; i<buff_count; i++) buff[i] = ' ';
            buff_count = 0; count++; check_point = 0;
        
        }
        
        if((i == len-1)&&(s[i] >= '0')&&(s[i] <= '9')) {
            
            *ptr[count] = (int)atoi(buff);
            
            if(s[check_point] == '-') {
                *ptr[count] = 0 -  *ptr[count];
            }
            
            for(int i=0; i<buff_count; i++) buff[i] = ' ';
            buff_count = 0; count++; check_point = 0;
            
        }
        
    }
    
    int n = 0;
    for(int i =0; i<count; i++) {
        //printf("%d\n",*ptr[i]);
        n = n + *ptr[i];
    }
    
    *sum = n;
    //printf("%d\n",n);
    
    return count;
    
}
#endif
