//
// Created by yangtao on 20-10-14.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace  std;
const int N = 50005;


int h[N << 2], e[N << 2], ne[N << 2], prev[N << 2];
double w[N << 2], val[N << 2];
int x[N], y[N], vis[N << 2];
int idx, n, m;

double dis(int x1, int y1, int x2, int y2) {
    return sqrt( (x1 - x2) * (x1 -x2) + (y1 - y2 ) * (y1 - y2) );
}

void add(int u, int v, double ww) {
    e[idx] = v, ne[idx] = h[u], w[idx] = ww, h[u] = idx++;
}

void dij(int xx, int yy) {
    for(int i = 1; i <= n; i++) val[i] = INF;
    memset(vis, 0, sizeof(vis));
    val[1] = 0 ;
    priority_queue< pair<double, int > > q;
    q.push(make_pair(0, 1));
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if( (u == xx && v == yy) || (u == yy && v == xx) ) continue;
            if( val[u] + w[i] < val[v]) {
                if(xx == -1 && yy == -1) prev[v] = u;
                val[v] = val[u] + w[i];
                q.push(make_pair(-val[v], v));
            }
        }
    }
}

int main() {

    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }

    for(int i = 1; i <= m ; i++) {
        int u, v;
        double d;
        scanf("%d%d", &u, &v);
        d = dis(x[u], y[u], x[v], y[v]);
        add(u, v, d), add(v, u, d);
    }

    dij(-1, -1);
    double ans = INF;
    for(int i = n; i != 1; i = prev[i]) {
        dij(i, prev[i]);
        ans = min(ans, val[n]);
    }

    if(ans >= INF) puts("-1");
    else printf("%.2lf", ans);

    return 0;

}

