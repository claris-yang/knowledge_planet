//
// Created by yangtao on 20-6-28.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 2e6 + 5;
int h[N], e[N], ne[N];
int n, m, idx;
struct Node {
    int x, y;
    bool operator<(const Node &node) const {
        return y > node.y;
    }
}nodes[N];
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

int vis[N];
queue<int> q;
void dfs(int u) {
    vis[u] = 1;
    printf("%d ", u);
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if(vis[v]) continue;
        dfs(v);
    }
}

void bfs() {
    memset(vis, 0, sizeof(vis));
    q.push(1);
    vis[1] = 1;

    while(q.size()) {
        int u = q.front();
        q.pop();
        printf("%d ", u);
        for(int i = h[u]; ~i ; i = ne[i]) {
            int v = e[i];
            if(vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
    }
}
int main() {

    memset(h, -1, sizeof(h));
    cin >> n >> m ;
    for(int i = 0 ;i < m; i++ ) {
        int u, v;
        scanf("%d%d", &nodes[i].x, &nodes[i].y);
    }
    sort(nodes, nodes + m);

    for(int i = 0 ; i < m; i ++ ) {
        add(nodes[i].x, nodes[i].y);
    }

    dfs(1);
    cout << endl;
    bfs();
    return 0;

}
