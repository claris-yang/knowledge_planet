//
// Created by yangtao on 20-11-30.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll size[N], dp[N], idx, cnt;
ll h[N], e[N<<1], ne[N<<1], w[N<<1], a[N];
void add(int u, int v, int ww) {
    e[idx] = v, ne[idx] = h[u], w[idx] = ww, h[u] = idx++;
}

void dfs1(int u, int fa) {
    size[u] = a[u];

    for(int i = h[u]; ~i ; i = ne[i]) {
        int v = e[i];
        if(v == fa) continue;
        dfs1(v, u);
        size[u] += size[v];
        dp[u] += dp[v] + size[v] * w[i];
    }

}

int n;
void dfs2(int u, int fa) {

    for(int i = h[u]; ~i; i = ne[i] ) {
        int v = e[i];
        if(v == fa) continue;
        dp[v] = dp[u] + (cnt - size[v] * 2) * w[i];
        dfs2(v, u);
    }
}
int main() {

    memset(h, -1, sizeof(h));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        cnt += a[i];
    }

    for(int i = 1; i < n; i++) {
        int x, y, ww;
        scanf("%d%d%d", &x, &y, &ww);
        add(x, y, ww), add(y, x, ww);
    }

    dfs1(1, 0);
    ll ans = dp[1];
    dfs2(1, 0);

    for(int i = 2; i <= n; i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;


}
