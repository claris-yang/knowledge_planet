//
// Created by yangtao on 20-10-21.
//
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 20005;
int h[N], f[N], ne[N<<1], e[N<<1], low[N], dfn[N], vis[N], stac[N], sd[N], in[N];
int p[N], res[N];
int n, m, idx, top, cnt, tot;

void add(int u, int v) {
    f[idx] = u, e[idx]=v, ne[idx]=h[u], h[u]=idx++;
}

void tarjan(int x) {
    dfn[x] = low[x] = ++cnt;
    stac[++top] = x; vis[x] = 1;
    for(int i = h[x]; ~i; i = ne[i]) {
        int v = e[i];
        if( !dfn[v] ) {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        } else if ( vis[v] ) {
            low[x] = min(low[x], dfn[v]);
        }
    }


    if( low[x] == dfn[x] ) {
        int y;
        tot++;
        while( stac[top+1] != x) {
            y = stac[top];
            sd[y] = tot;
            vis[y] = 0;
            top--;
            res[tot] =  min(res[tot], p[y]);
        }
    }
}

ll ans;

int main() {
    memset(h, -1, sizeof(h));
    memset(p, 0x3f, sizeof(p));
    memset(res, 0x3f, sizeof(res));
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[x] = y;
    }

    cin >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }

    for(int i = 1; i <= n; i++) {
        if(!dfn[i] && p[i] != 0x3f3f3f3f) tarjan(i);
    }

    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) {
            cout << "NO" << endl;
            cout << i << endl;
            return 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = h[i]; ~j ; j = ne[j]) {
            if(sd[i] != sd[e[j]]) {
                in[sd[e[j]]]++;
            }
        }
    }

    for(int i = 1; i <= tot; i++) {
        if(!in[i]) {
            ans += res[i];
        }
    }

    cout << "YES" << endl;
    cout << ans << endl;

    return 0;

}
