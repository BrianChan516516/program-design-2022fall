//
//  function.h
//  11711 - Dynamic 3D array(prac)
//
//  Created by Brian on 2022/12/11.
//

#ifndef function_h
#define function_h

#include <stdio.h>
#include <stdlib.h>

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k) {
    unsigned*** ln = malloc(n*sizeof(unsigned**));
    unsigned** lm = malloc(n*m*sizeof(unsigned*));
    unsigned* lk = malloc(n*m*k*sizeof(unsigned));
    
    for(int i=0; i<n; i++) {
        
        ln[i] = lm + i*m;
        
        for(int j=0; j<m; j++)
            ln[i][j] = lk + (i*m+j)*k;
        
    }
    
    return ln;
    
}
void delete_3d_array(unsigned ***arr) {
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}

#endif /* function_h */
