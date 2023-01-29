//
//  main.c
//  13086 - Golden Ratio Overheat
//
//  Created by Brian on 2023/1/7.
//

#include<stdio.h>
#include<string.h>

long long int t, f[60], n, k;
char s[2][2005];

void dfs(long long n,long long k) {
    if(n<2)
        printf("%c\n",s[n][k]);
    else if (k < f[n-2])
        dfs(n-2, k);
    else
        dfs(n-1, k-f[n-2]);
}

int main(void) {
    scanf("%lld", &t);
    while(t--){
        scanf("%s%s", s[0], s[1]);
        f[0] = strlen(s[0]);
        f[1] = strlen(s[1]);
        for(int i=2;i<60;++i)
            f[i] = f[i-2] + f[i-1];

        scanf("%lld%lld", &n, &k);
        dfs(n,k);
    }
}

