//
// Created by yangtao on 20-6-9.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 105;
int e[N], h[N], ne[N], w[N];
int n, idx, res = 0x3f3f3f3f, ans;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void dfs(int x, int fa, int level) {
    for(int i = h[x]; ~i; i = ne[i]) {
        int v = e[i];
        if(v == fa) continue;
        ans += level * w[v];
        dfs(v, x, level + 1);
    }
}
int main() {

    memset(h, -1, sizeof(h));
    cin >> n ;
    for(int i = 1; i <= n; i++) {
        int val, u, v;
        scanf("%d%d%d", &val, &u, &v);
        w[i] = val;
        if(u > 0) {
            add(i, u);
            add(u, i);
        }
        if(v > 0) {
            add(i , v);
            add(v , i);
        }
    }

    for(int i = 1; i <= n; i++ ) {
        ans = 0;
        dfs(i, -1, 1);
        res = min(res, ans);
    }

    cout << res << endl;
    return 0;
}