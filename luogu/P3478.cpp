//
// Created by yangtao on 20-11-27.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
ll h[N], e[N*2], ne[N*2], size[N], dep[N], dp[N];
int n, idx;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
void dfs1(int u, int f) {
    size[u] = 1, dep[u] = dep[f] + 1;
    for(int i = h[u]; ~i; i = ne[i] ) {
        int v = e[i];
        if(v == f) continue;
        dfs1(v, u);
        size[u] += size[v];
    }
}

void dfs2(int u, int f) {
    for(int i = h[u]; ~i ; i = ne[i]) {
        int v = e[i];
        if(v == f) continue;
        dp[v] = dp[u] - size[v] + n - size[v];
        dfs2(v, u);
    }
}

int main() {
    cin >> n;
    memset(h, -1 , sizeof(h));
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    dfs1(1, 0);
    for(int i = 1; i <= n; i++) dp[1] += size[i];
    dfs2(1, 0);
    ll ans = 0, mmax = 0;
    for(int i = 1; i <= n; i++) {
        if(dp[i] > mmax) {
            ans = i, mmax = dp[i];
        }
    }
    cout << ans;
    return 0;

}
