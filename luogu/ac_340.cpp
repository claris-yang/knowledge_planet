//
// Created by yangtao on 20-7-2.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 11000 ;
int h[N * 1000], e[N * 1000], ne[N * 1000], w[N * 1000], val[N * 1000];
int vis[N], n, k, p, idx;
priority_queue<pair<int, int> > q;
void add(int u, int v, int val) {
    e[idx] = v, ne[idx] = h[u], w[idx] = val, h[u] = idx++;
}

void dij(int s) {
    q.push({0, s});
    memset(val, 0x3f3f3f3f, sizeof(val));
    val[s] = 0;
    while(q.size()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            int vv = w[i];
            int mm = max(val[u], vv);
            if( val[v] > mm ) {
                val[v] = mm;
                q.push({-val[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> p >> k;
    memset(h, -1, sizeof(h));
    for(int i = 0 ;i < p ; i ++) {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        add(x, y, v);
        add(y, x, v);
        for(int j = 1 ;j <= k ;j++) {
            // j - 1 to j 层图
            add( x + (j-1) * n, y + j * n, 0);
            add( y + (j-1) * n, x + j * n, 0);
            // j to j 层图
            add(x + j * n, y + j * n , v);
            add(y + j * n, x + j * n , v);
        }
    }

    for(int i = 1; i <= k; i++) {
        add(n + (i-1) * n, n + i * n, 0);
    }

    dij(1);
    if(val[(k+1)*n] == 0x3f3f3f3f) puts("-1");
    else printf("%d", val[(k+1)*n]);
    return 0;

}
