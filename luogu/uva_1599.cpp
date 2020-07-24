//
// Created by yangtao on 20-7-1.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

struct Node {
    int x, y, v;
    bool operator<(const Node &node) const {
        return v > node.v;
    }
};
set<Node> s;
const int N = 4e5 + 5;
Node a[N];
int e[N],ne[N],h[N], w[N];
int idx, n, m;
pair<int, int> vis[N];
queue<pair<int, int> > q;
void add(int u, int v, int z) {
    e[idx] = v, ne[idx] = h[u], w[idx] = z, h[u] = idx++;
}
int res[N], k;
int bfs(int x) {
    vis[x].first = x;
    q.push({1, 0});
    while (q.size()) {
        int u = q.front().first;
        int step = q.front().second;
        if(u == n) return step;
        q.pop();
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(vis[v].first) continue;
            vis[v].first = u;
            vis[v].second = w[i];
            //cout << u << " " << v << " " << w[i] << endl;
            q.push({v, step+1});
        }
    }
    return 0;
}

void p(int x) {
    if(vis[x].first == x) {
        //printf("%d ", vis[x].second);
        return;
    }

    p(vis[x].first);
    printf("%d ", vis[x].second);
}

vector<Node> b;
int main( ) {
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for(int i = 0 ;i < m ; i++) {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
        b.push_back({a[i].x, a[i].y, a[i].v});
        b.push_back({a[i].y, a[i].x, a[i].v});
    }
    sort(b.begin(), b.end());
    //cout << " -  -----   " << endl;
    for(auto a : b) {
        //cout << a.x << " " << a.y << " " << a.v << endl;
        add(a.x, a.y, a.v);
    }

    //cout << " ---- " << endl;

    int step = bfs(1);

    cout << step << endl;
    p(n);

    return 0;

}