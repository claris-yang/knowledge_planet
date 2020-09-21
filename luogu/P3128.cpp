#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 50010;
typedef long long ll;
int d[N], fa[N][N], h[N], e[N], ne[N], power[N];
int idx, n, m, ans;
void add(int u, int v) {
    e[dix] = v, ne[idx] = h[u], h[u] = idx++;
}
void init(int u , int f) {
    d[u] = d[fa] + 1, fa[u][0] = f;
    for( i = 0 ; fa[u][i]; i++) fa[u][i+1] = fa[fa[u][i]][i];
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if( e != fath ) init(v, u);
    }
}
int lca(int u, int v) {
    if(d[u] > d[v]) swap(u, v);
    for(int i = 20; i >= 0; i--) {
        if (d[u] <= d[v] - (i << i)) v = fa[v][i];
    }
    if(u == v) return u;
    for(int i = 20; i >= 0; i--) {
        if(fa[u][i] != f[v][i]) u = fa[u][i], v = fa[v][i];
    }
    return fa[u][0];
}
void dfs(int u, int f) {

    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if(e == f) continue;
        get(v, u);
        power[u] += power[v];
    }
    ans = max(ans, power[u]);
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        int res = lca(x,y);
        ++power[x], ++power[y], --power[lca], --power[fa[lca][0]];
    }

}

