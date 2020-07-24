//
// Created by yangtao on 20-6-16.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 40005;

int n, m, s, t, idx;
int e[N], ne[N], h[N];
bool vis[N];
struct Node {
    int u, step;
};
queue<Node> q;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
int bfs() {
    q.push({s, 0});
    vis[s] = true;
    while(!q.empty()) {
        Node node = q.front();
        q.pop();
        for(int i = h[node.u]; ~i; i = ne[i]) {
            int v = e[i];
            if(v == t) {
                return node.step + 1;
            }
            if(!vis[v]) {
                q.push({v, node.step+1});
                vis[v] = true;
            }

        }
    }
    return 0;
}
int main() {
    memset(h, -1, sizeof(h));
    cin >> n >> m >> s >> t;
    for(int i = 0 ;i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    int res = 0;
    if( res = bfs()) {
        cout << res << endl;
    } else {
        cout << "No path";
    }
    return 0;
}