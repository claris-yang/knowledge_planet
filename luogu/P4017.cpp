//
// Created by yangtao on 20-6-30.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 500005;
int e[N], ne[N], h[N], z[N];
int idx, n, m;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
int vis[N],ans, res;

int dfs(int x) {

    int t = 1;
    for(int i = h[x] ; ~i; i = ne[i]) {
        int v = e[i];
        if(vis[v]) continue;
        vis[i] = 1;
        t += dfs(v);
    }

    return res *= t;
}
int main() {

    memset(h, -1, sizeof(h));
    cin >> n >>  m;

    for(int i = 0; i < m; i++ ) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(v, u);
        z[u]++;
    }
    for(int i = 1; i <= n; i++) {
        if(!z[i]) {
            res = 1;
            if(!vis[i]) {
                memset(vis, 0 , sizeof(vis));
                vis[i] = 1;
                ans += dfs(i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
