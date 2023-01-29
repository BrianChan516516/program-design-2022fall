//
//  main.c
//  12510 - Hakka's Maze
//
//  Created by Brian on 2022/12/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int n, m;
char s[1010][1010];
bool vis[1010][1010];
bool can_teleport;

void dfs(int x, int y) {
    
    if(vis[x][y] == true)
        return;
    
    vis[x][y] = true;
    
    if(s[x][y] == 'T')
        can_teleport = true;
       
    char dx[] = {1, -1, 0, 0};
    char dy[] = {0, 0, 1, -1};
    
    for(int i=0; i<4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(s[newx][newy] == '#')
            continue;
        if(newx < 0 || newy < 0 || newx >= n || newy>= m)
            continue;
        dfs(newx,newy);
    }
 }

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        
        scanf("%d %d\n", &n , &m);
        
        for(int i=0; i<n; i++)
            scanf("%s", s[i]);
        
        memset(vis, false, sizeof(vis));//sizeof(vis)!!!!
        can_teleport = false;//在這邊將can_teleport 設為 false;
        dfs(0,0);
        
        if(can_teleport == true) {
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    if(s[i][j] == 'T')
                        dfs(i,j);
        }
        
        if(vis[n-1][m-1] == true) printf("Yes\n");
        else printf("No\n");
        
    }
}
