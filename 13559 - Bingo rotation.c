//
//  main.c
//  13559 - Bingo rotation
//
//  Created by Brian on 2022/10/8.
//

#include <stdio.h>

int main(void) {
    
    int n;
    int angle;
    int arr[100][100];
    
    scanf("%d",&n);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&arr[i][j]);
    
    scanf("%d",&angle);
    
    if(angle == 0) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(j != n-1) {
                    printf("%d ",arr[i][j]);
                }else printf("%d",arr[i][j]);
            }
            /*if(i != n-1)*/ printf("\n");
        }
    } else if(angle == 90) {
        for(int j = n-1; j>=0; j--) {
            for(int i=0; i<n; i++) {
                if(i != n-1) {
                    printf("%d ",arr[i][j]);
                }else printf("%d",arr[i][j]);
            }
            /*if(j != 0)*/ printf("\n");
        }
    } else if(angle == 180){
        for(int i = n-1; i>=0; i--) {
            for(int j = n-1; j>=0; j--) {
                if(j != 0) {
                    printf("%d ",arr[i][j]);
                }else printf("%d",arr[i][j]);
            }
            /*if(i != 0)*/ printf("\n");
        }
    } else if(angle == 270) {
        for(int j = 0; j<n; j++) {
            for(int i = n-1; i>=0; i--) {
                if(i != 0) {
                    printf("%d ",arr[i][j]);
                }else printf("%d",arr[i][j]);
            }
            /*if(j != n-1)*/ printf("\n");
        }
    } else return 1;
    
    return 0;
    
}
