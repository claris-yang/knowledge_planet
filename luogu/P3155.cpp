//
// Created by yangtao on 20-8-20.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e4 + 5;
typedef  long long ll;
int h[N], e[N * 2], ne[N * 2], a[N], f[N][4];
int idx, n, m, fa;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
void dfs(int u, int fa) {
    if(u <= n) return ;
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if(v != fa) {
            dfs(v, u);
            f[u][0] += min(f[v][0]-1, f[v][1]);
            f[u][1] += min(f[v][1]-1, f[v][0]);
        }
    }
}
int main() {
    memset(h, -1, sizeof(h));
    cin >> m >> n;
    fa = n + 1;
    for(int i = 1; i <= n; i++)  {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    for(int i = 1; i <= m; i++) {
        f[i][0] = f[i][1] = 1;
        if(i <= n ) f[i][(!a[i])] = INF;
    }
    dfs(fa, fa);
    printf("%d", min(f[fa][0], f[fa][1]));
    return 0;
}