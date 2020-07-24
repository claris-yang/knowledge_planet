//
// Created by yangtao on 20-6-2.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5005;
int d[N], v[N];
int a[N][N];
int n, m, ans;
void prim() {
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    for(int i = 1; i < n; i++) {
        int x = 0;
        for(int j = 1; j <= n ; j++) {
            if( !v[j] && (x == 0 || d[j] < d[x])) x = j;
        }
        v[x] = 1;
        for(int j = 1; j <= n; j++) {
            if(!v[j]) d[j] = min(d[j], a[x][j]);
        }
    }

}
int main() {
    cin >> n >> m;
    memset(a, 0x3f, sizeof(a));
    for(int i = 1; i <= n; i++) a[i][i] = 0;
    for(int i = 1; i <=m ; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[y][x] = a[x][y] = min(a[x][y], z);
    }
    prim();
    for(int i = 2; i<= n; i++) ans += d[i];
    cout << ans << endl;
    return 0;
}