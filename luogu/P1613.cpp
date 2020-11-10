//
// Created by yangtao on 20-9-27.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 65;
int dis[N][N];
bool c[N][N][60];

int n,m;
void floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}
int main( ) {

    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));

    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        dis[x][y] = c[x][y][0] = 1;
    }

    for(int z = 1; z <= 30; z++) {
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if( c[i][k][z-1] && c[k][j][z-1])
                        dis[i][j] = c[i][j][z] = 1;

                }
            }
        }
    }

    floyd();
    cout << dis[1][n];
    return 0;

}