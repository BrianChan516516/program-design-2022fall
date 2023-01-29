//
//  function.h
//  11711 - Dynamic 3D array
//
//  Created by Brian on 2022/12/7.
//

#ifndef function_h
#define function_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k) {
    
    unsigned ***ln = (unsigned***) malloc(n*sizeof(unsigned**));
    unsigned **lm = (unsigned**) malloc(n*m*sizeof(unsigned*));
    unsigned *lk = (unsigned*) malloc(n*m*k*sizeof(unsigned));
        
    for(int i=0; i<n; i++) {
        
        ln[i]=lm+i*m;
        
        for(int j=0; j<m; j++)
            ln[i][j]=lk+(i*m+j)*k;
    }
    
    return ln;
}

void delete_3d_array(unsigned ***arr) {
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
    return;
}

#endif /* function_h */
