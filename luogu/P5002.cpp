//
// Created by yangtao on 20-8-5.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
const int P = 1e9 + 7;
typedef  long long ll;
int h[N], e[N * 2], ne[N * 2];
bool vis[N];
int n, m, r, idx, ans[N];
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

ll dfs(int u) {
    vis[u] = true;
    ll tot = 1;
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if(!vis[v]) {
            ll w = dfs(v);
            ans[u] += tot * w * 2, ans[u] %= P, tot += w;
        }
    }
    return tot;
}
int main() {
    memset(h, -1, sizeof(h));
    cin >> n >> r >> m;
    for(int i = 1; i < n; i++) {
        int x, y;
        ans[i] = 1;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    ans[n] = 1;
    dfs(r);
    for(int i = 1 ; i <= m; i++) {
        int t ;
        scanf("%d", &t);
        printf("%d\n", ans[t]);
    }
    return 0;
}
