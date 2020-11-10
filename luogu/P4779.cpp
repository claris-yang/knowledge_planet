//
// Created by yangtao on 20-10-15.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

struct Edge {
    int v, w;
    Edge(int v, int w) : v(v), w(w) {};
};

vector<Edge> adj[N];
bool vis[N];
int d[N];

struct Node {
    int v, dis;
    bool operator<(const Node &node) const {
        return dis > node.dis;
    };
    Node(int v, int dis) : v(v), dis(dis) {};
};
priority_queue<Node> q;

void dij(int s ) {
    d[s] = 0 ;
    q.push(Node(s, 0));
    while(!q.empty()) {
        int u = q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v;
            int dis = adj[u][i].w;
            if( dis + d[u] < d[v]) {
                d[v] = dis + d[u];
                q.push(Node(v, d[v]));
            }
        }
    }
}

int n, m, s;
int main() {
    cin >> n >> m >> s;
    for(int i = 1; i <=m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(Edge{ v, w});
    }
    for(int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    dij(s);
    for(int i = 1; i <= n; i++) {
        printf("%d ", d[i]);
    }
    return 0;
}