//
// Created by yangtao on 20-9-30.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5e4 + 5;
int h[N], e[N], ne[N], dfn[N], low[N], num[N], st[N];
bool vis[N];
int idx, n, m, cnt, top, color;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void tarjan(int x) {
    dfn[x] = low[x] = ++cnt;
    st[++top] = x;
    vis[x] = true;
    for(int i = h[x]; ~i ; i = ne[i]) {
        int v = e[i];
        if(!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        } else if(vis[v]){
            low[x] = min(low[x], dfn[v]);
        }
    }

    if(low[x] == dfn[x]) {
        int y;
        color++;
        while( y = st[top--]) {
            num[color]++;
            vis[y] = false;
            if(x == y) break;
        }
    }

}

int main() {
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) {
            tarjan(i);
        }
    }

    int ans = 0;
    for(int i = 1; i <= color; i++) {
        if(num[i] > 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
