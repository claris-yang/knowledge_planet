//
// Created by yangtao on 20-7-6.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int  N = 1e5 + 5;

int u[N], e[N], ne[N], idx;
int fa[N], dep[N], siz[N], son[N];
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] = + 1;
    siz[u] = 1;
    int maxsize = -1;
    for(int i = h[u], ~i; i = ne[i]) {
        int v = e[i];
        if(v == f) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[v] > maxsize) {
            maxsize = siz[v];
            son[u] = v;
        }
    }
}

int tim, dfn[N], top[N], w[N];
void dfs2(int u, int t) {
    dfn[u] = ++tim;
    top[u] = t;
    w[tim] = v[u];
    if(!son[u]) return;
    dfs2(son[u], t);
    for(int i = h[u]; ~i; i = ne[i]) {
        int v= e[i];
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

inline void mson(int x, int z) {
    modify(dfn[x], dfn[x] + siz[x] -1, z);
}

inline int qson(int x) {
    return query(dfs[x], dfn[x] + siz[x] - 1);
}

void mchain(int x, int y, int z) {
    z %= mod;
    while( top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]])
            swap(x, y);
        modify(dfn[top[x]], dfn[x], z);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y])
        swap(x, y);
    modify(dfn[x], dfn[y], z);

}

int qchain(int x, int y) {
    int ret = 0;
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]])
            swap(x, y);
        ret += query(dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y])
        swap(x, y);
    ret += query(dfn[x], dfn[y]);
    return ret % mod;
}

int main() {
    dfs1(r, r);
    dfs2(r, r);
    build(1, n);
}