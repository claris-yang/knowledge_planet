//
// Created by yangtao on 20-8-3.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int> q;
const int N = 1e5;
int a[N], in[N];
int h[N], e[N], ne[N];
int n, m, idx;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
void topo() {
    for(int i = 1; i <=n; i++ ) {
        if(!in[i]) q.push(-i);
    }
    while(q.size()) {
        int  u = -q.top();
        q.pop();
        printf("%d ", u);
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            in[v]--;
            if(!in[v]) {
                q.push(-v);
            }
        }
    }

}
int main() {
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for(int i = 1; i <=m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        in[v]++;
    }
    topo();
    return 0;
}