//
//  main.c
//  13557 - Anya coin ga suki
//
//  Created by Brian on 2022/9/18.
//

#include <stdio.h>

int main(void) {
    
    int one_dol, fiv_dol, ten_dol, fif_dol;
    int fare;
    int num = 0;
    
    scanf("%d %d %d %d %d", &fare, &one_dol, &fiv_dol, &ten_dol, &fif_dol );
    //test case : 31 8 3 1 1
    //printf("0:%d\n",fare);
    
    if(fare >= 50) {
        while((fif_dol > 0)&&(fare >= 50)) {
            fare  = fare - fif_dol;
            fif_dol--;
            num++;
            //printf("1:%d\n",fare);
        }
    }
    
    //printf("%d\n",num);
    
    if(fare >= 10) {
        while((ten_dol > 0)&&(fare >= 10)) {
            fare  = fare - 10;
            ten_dol--;
            num++;
            //printf("2:%d\n",fare);
        }
    }
    
    //printf("%d\n",num);
    //printf("%d\n",fare);
    
    if(fare >= 5) {
        while((fiv_dol > 0) && (fare >= 5)) {
            fare  = fare - 5;
            fiv_dol--;
            num++;
            //printf("3:%d\n",fare);
        }
    }
    
    //printf("%d\n",num);
    //printf("%d\n",fare);
    
    if(fare >= 1) {
        while((one_dol > 0) && (fare >= 1)) {
            fare  = fare - 1;
            one_dol--;
            num++;
            //printf("4:%d\n",fare);
        }
    }
    if(fare == 0) printf("%d\n",num);
    else printf("-1\n");
    
    return 0;
    
   // printf("%d %d",num, fif_dol);
    
}
