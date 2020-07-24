//
// Created by yangtao on 19-11-22.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 205;
int n, m;
int a[N];
int adj[N][N];
int q;
void floyd(int k) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(adj[i][j] > adj[i][k] + adj[j][k])
                adj[j][i] = adj[i][j] = adj[i][k] + adj[j][k];
        }
    }
}
int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

   memset(adj, 0x3f, sizeof(adj));

    for(int i =  0; i < n ; i++) adj[i][i] = 0;

    for(int i = 0 ;i < m; i++)
    {
        int x, y, t;
        scanf("%d%d%d", &x, &y , &t);
        adj[x][y] = adj[y][x] = t;
    }

    scanf("%d", &q);

    int now = 0 ;

    while( q-- > 0) {
        int x, y, t;
        scanf("%d%d%d", &x, &y, &t);

        while( a[now] <= t && now < n) {
            floyd(now++);
        }

        // 判断一下节点是否存在
        if( a[x] > t || a[y] > t)
            puts("-1");
        else if(adj[x][y] == 0x3f3f3f3f)
            puts("-1");
        else
            printf("%d\n", adj[x][y]);
    }

    return 0;
}