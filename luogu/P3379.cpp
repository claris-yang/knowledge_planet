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
int n, m, s;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
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
        dfs(v, u);
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
}
