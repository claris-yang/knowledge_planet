//
// Created by yangtao on 20-7-2.
//


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 1000010;
int n, m, idx;
int e[N * 4], ne[N * 4], w[N * 4], h[N * 4], d[N * 4], vis[N*4], a[N*4];
void add(int u, int v, int val) {
    e[idx] = v, ne[idx] = h[u], w[idx] = val, h[u] = idx++;
}
queue<int> q;

int cnt;
void spfa() {
    for(int i = 1; i <= n; i++) d[i] = -0x3f3f3f3f;
    d[1] = 0;
    vis[1] = 1;
    q.push(1);

    while(q.size()) {
        int u = q.front(); q.pop();
        cout << "node = " << u << endl;
        vis[u] = 0;
        for(int i = h[u]; ~i; i = ne[i]) {
            cnt++;
            if(cnt > 1000000)
                cout << i << endl;
            int v = e[i];
            if(d[v] < d[u] + w[i]) {
                d[v] = d[u] + w[i];
                if(vis[v]==0) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

int main() {
    freopen("d.txt","r", stdin);
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, 0);
        add(x, y + n, -a[x]);
        add(x + n, y + n, 0);
        add(x + n, y + 2 * n, a[x]);
        add(x + 2 * n, y + 2 * n, 0);
        if(z == 2) {
            add(y,  x, 0);
            add(y , x + n, -a[y]);
            add(y + n, x + n, 0);
            add(y + n,  x + 2 * n, a[y]);
            add(y + 2 * n, x + 2 * n, 0);
        }
        cout << "beinig" << i << endl;
    }
    cout <<"beijing" << endl;
    add(n , 3 *n , 0);
    add(3 * n, 3 * n + 1, 0);
    n = 3 * n + 1;
    spfa();
    cout << d[n] << endl;
    return 0;
}