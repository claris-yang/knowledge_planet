//
// Created by yangtao on 20-8-5.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 500005;
int h[N], e[N * 2], ne[N * 2], dep[N];
int f[N][25];
int n, m, s , idx;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

int lca(int x, int y ) {
    if ( dep[x] < dep[y]) {
        swap(x, y);
    }
    for(int i = 20; i >= 0; i--) {
        if(dep[f[x][i]] >= dep[y]) {
            x = f[x][i];
        }
    }
    if(x == y)
        return x;
    for(int i = 20; i >= 0; i-- ) {
        if(f[x][i] == f[y][i]) {
            continue;
        }
        x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}
void dfs(int c, int fa) {
    dep[c] = dep[fa] + 1;
    f[c][0] = fa;
    for(int i = 1 ; (1 << i ) <= n; i++) {
        f[c][i] = f[f[c][i-1]][i-1];
    }
    for(int i = h[c]; ~i; i = ne[i]) {
        int v = e[i];
        if(v == fa) continue;
        dfs(v, c);
    }
}

void pre() {
    for(int i = 1; i <= 20 ; i++) {
        for(int j = 1; j <= n; j++) {
            f[j][i] = f[f[j][i-1]][i-1];
        }
    }
}
int main() {
    cin >> n >> m >> s;
    memset(h, -1, sizeof(h));
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    dfs(s, 0);
    pre();

    for(int i = 1; i <=m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}
