//
// Created by yangtao on 20-9-28.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 16005;
int a[N], dp[N];
int h[N], e[N*2], ne[N*2];
int cnt, n, ans;
void add(int u , int v) {
    e[cnt] = v, ne[cnt] = h[u], h[u] = cnt++;
}
int dfs(int u, int f) {
    dp[u] = a[u];
    for(int  i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if(v != f ) {
            int res = dfs(v, u);
            dp[u] += max(0, res);
        }
    }
    ans = max(ans, dp[u]);
    return dp[u];

}
int main() {
    cin >> n;
    memset(h, -1, sizeof(h));
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    dfs(1, 0);
    cout << ans ;
    return 0;
}