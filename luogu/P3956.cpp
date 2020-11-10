//
// Created by yangtao on 20-10-15.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 105;
int a[N][N], f[N][N];
int n, m;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int ans = 0x3f3f3f3f;
void dfs(int x, int y , int sum, bool flag) {

    if( 1 > x || 1 > y || x > n || y > n ) {
        return ;
    }
    if( f[x][y] <= sum ) {
        return ;
    }
    f[x][y] = sum;
    if(x == n && y == n) {
        ans = min(ans, sum);
        return ;
    }

    for(int i = 0 ; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if( a[xx][yy] ){
            if( a[x][y] == a[xx][yy]) {
                dfs(xx, yy, sum, false);
            } else {
                dfs(xx, yy, sum + 1, false);
            }
        } else if (!flag) {
            a[xx][yy] = a[x][y];
            dfs(xx, yy, sum + 2, true);
            a[xx][yy] = 0;
        }
    }

}
int main() {
    cin >> n >> m;
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= m ; i++) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        a[x][y] = c + 1;
    }

    dfs(1, 1, 0, false);

    printf("%d", (ans == 0x3f3f3f3f) ? -1 : ans);
    return 0;
}
