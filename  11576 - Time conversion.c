//
//  main.c
//  11576 - Time conversion
//  Created by Brian on 2022/9/22.
//

#include <stdio.h>

int main(void) {
    
    int time;
    int hr, min;
    
    scanf("%d", &time);
        
    hr = time/100;
    min = time%100;
    
    //if((hr>24)||(min>60)) return 0;
    
    if((hr >= 0) && (hr < 12)) printf("%02d:%02d a.m.",hr ,min);
    else if(hr == 12) printf("00:%02d p.m.",min);
    else if((hr > 12) && (hr < 24)) printf("%02d:%02d p.m.",hr - 12 ,min); //in case p.m. hr = hr(24) - 12
    else if (hr == 24) printf("00:%02d a.m.",min);
    else return 1;
        
    return 0;
}
