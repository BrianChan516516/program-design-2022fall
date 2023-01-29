//
//  main.c
//  13591 - Second Highest Value
//
//  Created by Brian on 2022/10/15.
//

#include <stdio.h>

int main(void) {
    
    int num = 0;
    int arr[1000005] = {0};
    int ans[1000005] = {0};
    int max =0 ,second = 0;
    
    scanf("%d",&num);
    for(int i=0; i<num; i++) scanf("%d",&arr[i]);
    //finish scanning, start sorting
    
    for(int i=0; i<num; i++) {
        
        if(arr[i]>=max) {
            second = max;
            max = arr[i];
        }else if((arr[i] >= second)&&(arr[i] < max)) {
            second = arr[i];
        }
        
        //printf("max=%d second=%d, ",max,second);
        ans[i] = second;
    }//finish sorting
    
    for(int i=0; i<num; i++) {
        if(i==num-1) printf("%d",ans[i]);
        else printf("%d ",ans[i]);
    }
    printf("\n");
    
    return 0;
}
