//
// Created by yangtao on 19-11-15.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int N  = 1e5 + 5;
int n, m;

struct Edge {
    int town, dis;
    bool operator<(const Edge & node ) const {
        return dis > node.dis;
    }
};

struct Node {
    int v, w;
};

struct
priority_queue<Edge> q;
vector<Node> adj[N];
vector<int> ans;
bool vis[N] ;
int dis[N];
int pre[N];

int add (int a, int b) {
    if( a + b > 0x3f3f3f3f) return 0x3f3f3f3f;
    else a + b;
}

int main() {
    cin >> n >> m;

    for(int i = 0 ;i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(Node{v, w});
        adj[v].push_back(Node{u, w});
    }

    memset(dis, 0x3f, sizeof(dis));

    dis[1] = 0;

    q.push(Edge{1, 0});

    while(!q.empty()) {
        Edge e = q.top();
        q.pop();
        if(vis[e.town]) continue;
        vis[e.town] = true;
        for(int i = 0; i < adj[e.town].size(); i++) {

            int v = adj[e.town][i].v;
            int w = adj[e.town][i].w;
            if( w + dis[e.town] < dis[v]) {
                dis[v] = add(dis[e.town] , w);
                q.push(Edge{v, dis[v]});
                pre[v] = e.town;
            }

        }
    }

    if(dis[n] == 0x3f3f3f3f ) {
        puts("-1");
    } else {
        int t = n;
        while( t != 1) {
            ans.push_back(t);
            t = pre[t];
        }
        printf("1 ");
        for(int i = ans.size() - 1 ; i >= 0; i--) {
            printf("%d ", ans[i]);
        }

    }
    return 0;
}
