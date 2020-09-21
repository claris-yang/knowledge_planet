//
// Created by yangtao on 20-8-17.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 3005;
int f[N][N];
int a[N], h[N], e[N], ne[N], w[N];
int n, m, idx;
void add(int u, int v, int val) {
    e[idx] = v, ne[idx] = h[u], w[idx] = val, h[u] = idx++;
}

int dfs(int u) {
    if(u >= n - m + 1) {
        f[u][1] = a[u];
        return 1;
    }
    int sum = 0;
    for(int i = h[u]; ~i ; i = ne[i]) {
        int v = e[i];
        int t = dfs(v);
        sum += t;
        for(int j = sum ; j >= 0 ; j--) {
            for(int k = 1; k <= t; k++) {
                if(j >= k) {
                    f[u][j] = max(f[u][j], f[u][j-k] + f[v][k] - w[i]);
                }
            }
        }
    }
    return sum;
}
int main() {
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    memset(f, -0x3f, sizeof(f));
    for( int i = 1;  i <= n - m ; i++) {
        int t;
        scanf("%d", &t);
        for(int j = 1; j <= t; j++) {
            int v, val;
            scanf("%d%d", &v, &val);
            add(i, v, val);
        }
    }
    for(int i = n - m + 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) f[i][0] = 0;
    dfs(1);

    for(int i = m; i > 0; i--) {
        if(f[1][i] >= 0) {
            cout << i ;
            break;
        }
    }
    return 0;

}