//
// Created by yangtao on 19-12-2.
//

#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1505;

int n,m;
queue<int> q;
int dis[N];

struct Edge{
public:
    int v, w;
};

vector<Edge> edges[N];
bool vis[N];

void SPFA(int s) {

    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push(s);
    vis[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = 0; i < edges[u].size(); i++) {
            int v = edges[u][i].v;
            int w = edges[u][i].w;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

}

int main() {
    scanf("%d%d", &n, &m);

    for(int i = 1; i <=m; i++) {
        int x;
        Edge e;
        scanf("%d%d%d", &x, &e.v, &e.w);
        e.w = 0 - e.w;
        edges[x].push_back(e);
    }

    SPFA(1);

    if(dis[n] == 0x3f3f3f3f) {
        puts("-1");
    } else {
        printf("%d\n", -dis[n]);
    }

    return 0;
}