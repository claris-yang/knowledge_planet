//
// Created by yangtao on 20-7-2.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e6 +5 , M = 1e7 + 5;
int n, m, k, idx;
int h[N], e[M], ne[M], w[M], dis[N], vis[N];
priority_queue<pair<int, int> > q;
void add(int u, int v, int val) {
    e[idx] = v, ne[idx] = h[u], w[idx] = val, h[u] = idx++;
}
void dij(int s) {
    q.push({0, s});
    memset(dis, 0x3f3f3f3f, sizeof(h));
    dis[s] = 0;
    while (q.size()  ) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(dis[v] > dis[u] + w[i]) {
                dis[v] = dis[u] + w[i];
                q.push({-dis[v], v});
            }
        }
    }
}

int main() {
    memset(h, -1, sizeof(h));
    cin >> n >> m >>k;
    for(int i = 1; i <= m; i++) {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        add(x, y, v);
        add(y, x, v);
        for(int j = 1; j <= k; j++) {
            add(x + (j-1) * n, y + j * n, 0);
            add(y + (j-1) * n, x + j * n, 0);
            add(x + j*n, y + j * n, v);
            add(y + j*n, x + j * n, v);
        }
    }
    for(int i = 1; i <= k;  i++) {
        add(i * n, (i+1) * n , 0);
    }

    dij(1);

    if(dis[(k+1)*n] == 0x3f3f3f3f) puts("-1");
    else printf("%d", dis[(k+1)*n]);
    return 0;
}
