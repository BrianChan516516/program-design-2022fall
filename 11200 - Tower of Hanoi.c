//
//  main.c
//  11200 - Tower of Hanoi
//
//  Created by Brian on 2022/11/6.
//
  
#include <stdio.h>

void hanoi(int n, char A, char B, char C/*auxiliary rod*/) {
    if(n == 1) printf("move disk 1 from rod %c to rod %c\n", A, B);
    else {
        hanoi(n-1, A, C, B);
        printf("move disk %d from rod %c to rod %c\n",n , A, B);
        hanoi(n-1, B, A, C);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

/*
For example, if n = 3, the moves of each steps are:
move disk 1 from rod A to rod C
move disk 2 from rod A to rod B
move disk 1 from rod C to rod B
move disk 3 from rod A to rod C
move disk 1 from rod B to rod A
move disk 2 from rod B to rod C
move disk 1 from rod A to rod C
*/
