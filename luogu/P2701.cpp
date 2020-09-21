//
// Created by yangtao on 20-8-26.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
bool d[N][N];
int n, m, f[N][N];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        d[x][y] = true;
    }
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++) {
        f[0][0] = f[0][i] = f[i][0] = 0;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!d[i][j]) {
                int t = min(f[i-1][j], f[i][j-1]);
                f[i][j] = min(f[i-1][j-1], t) + 1;
            } else {
                f[i][j] = 0;
            }
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << endl;
    return 0;

}

