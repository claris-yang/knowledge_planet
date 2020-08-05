//
// Created by yangtao on 20-8-5.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 500010;
int fa[N][25], dep[N], lg[N];
int h[N], e[N*2], ne[N*2];
int idx, n, m;
void add(int u, int  v ) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
void dfs(int c, int f) {
    fa[c][0] = f;
    dep[c] = dep[f] + 1;
    for(int i = 1; (1 << i) <= dep[c]; i++) {
        fa[c][i] = fa[fa[c][i-1]][i-1];
    }
    for(int i = h[c]; ~i; i = ne[i]) {
        int v = e[i];
        if(v == f) continue;
        dfs(v, c);
    }
}
int lca(int x, int y) {

    if(dep[x] < dep[y]) {
        swap(x, y);
    }
    while(dep[x] > dep[y]) {
        x = fa[x][lg[dep[x] - dep[y]] - 1 ];
    }
    if(x == y)
        return x;
    for(int k = lg[dep[x]]; k >= 0; k--) {
        if(fa[x][k] != fa[y][k]) {
            x = fa[x][k];
            y = fa[y][k];
        }
    }
    return fa[x][0];
}
int main() {
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }

    dfs(1, 0);
    for(int i = 1; i <= n; i++) {
        lg[i] = lg[i-1] + ((1 << lg[i-1]) == i);
    }

    for(int i = 1; i <=m; i++) {
        ll ans = 0;
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int c1 = lca(x, y);
        int c2 = lca(y, z);
        int c3 = lca(x, z);
        int c;
        if(c1 == c2) {
            c = c3;
        } else if(c1 == c3) {
            c = c2;
        } else if(c3 == c2) {
            c = c1;
        }
        ans = dep[x] + dep[y] + dep[z] - dep[c1] - dep[c2] - dep[c3];
        printf("%d %lld\n", c, ans);
    }
    return 0;
}