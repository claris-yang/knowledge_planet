//
// Created by yangtao on 20-6-30.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
int k,n,m, idx;
int e[N], ne[N], h[N], vis[N], s[N];
int a[N], ans;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
void dfs(int x) {
    vis[x] = 1;
    s[x]++;
    for(int i = h[x]; ~i; i = ne[i]) {
        int v = e[i];
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v);
    }
}

int main() {
    cin >> k >> n >> m;

    memset(h , -1, sizeof(h));
    for(int i = 1; i <= k ; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0 ;i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }

    for(int i = 1; i <= k; i++) {
        dfs(a[i]);
        memset(vis, 0 , sizeof(vis));
    }

    for(int i = 1; i <= n; i++) {
        if(s[i] == k) ans++;
    }

    cout << ans << endl;

    return 0;
}
