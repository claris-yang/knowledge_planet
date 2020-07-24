//
// Created by yangtao on 19-11-26.
//
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 3000;
const int inf = 0x3f3f3f3f;
int n, p, c;
int m[N];
bool vis[N];

int nc[N], head[N], w[N], e[N];
int idx;
queue<int> q;
int d[N];

int zz;
void SPFA(int s) {

    memset(vis, false, sizeof(vis));
    memset(d, 0x3f, sizeof(d));

    d[s] = 0;
    vis[s] = true;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; ~i; i = nc[i]) {
            int v = e[i];
            if( w[i] + d[u] < d[v]) {
                d[v] = w[i] + d[u];
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}

void add(int x, int y, int d) {
    e[idx] = y, w[idx] = d, nc[idx] = head[x], head[x] = idx++;
}

int res = inf ;
int main() {

    memset(head, -1, sizeof(head));
    cin >> n >> p >> c;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m[i]);
    }

    for(int i = 1 ; i <= c; i++) {
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        add(x, y, d);
        add(y, x, d);
    }

    for(int i = 1; i <= p; i++) {
        SPFA(i);
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            if( d[m[j]] != inf ) {
                sum += d[m[j]];
            }
        }
        res = min(res, sum);
    }

    printf("%d\n", res);

    return 0;
}