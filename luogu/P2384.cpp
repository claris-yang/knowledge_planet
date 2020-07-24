//
// Created by yangtao on 19-12-3.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
const int inf = 2147483647;
const int N = 1005;
struct Node {
    int u, v, w;
};
struct Edge {
    int u;
    double dis;
    bool operator<(const Edge & e) const {
        return dis > e.dis;
    }
};
priority_queue<Edge> q;
int n,m;
vector<Node> vec[N];
double dis[N];
bool vis[N];
int ans = 1;
int pre[N];
int idx ;
int po[N][2];
void dij(int s) {

    for(int i = 1; i <= n; i++) {
        dis[i] = inf;
    }

    dis[s] = 1;
    Edge e;
    e.u = s;
    e.dis = 1;
    q.push(e);
    while(!q.empty()) {
        Edge e = q.top();
        q.pop();
        int u = e.u;
        if(vis[u]) continue;
        vis[u] = true;
        pre[idx++] = u;
        for(int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i].v;
            int w = vec[u][i].w;
            double t = log(w) * dis[u];
            if( t < dis[v]) {
                Edge e;
                e.u = v;
                dis[v] = e.dis = t;
                q.push(e);
                po[v][0] = u; po[v][1] = w;
            }
        }
    }
}
int main() {
    scanf("%d%d", &n , &m);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        Node e;
        e.u = u;
        e.v = v;
        e.w = w;
        vec[u].push_back(e);
        e.u = v;
        e.v = u;
        vec[u].push_back(e);
    }

    dij(1);

    int ans = 1;
    /*
    for(int i = 1; i < idx; i++) {
        for(int j = 0; j < vec[pre[i-1]].size() ; j++) {
            if(pre[i] == vec[pre[i-1]][j].v) {
                ans = vec[pre[i-1]][j].w * ans % 9987;
                printf("ans = %d\n", ans);

                break;
            }
        }

    }*/
    int pos = n;
    while(pos != 1) {
        ans *= po[pos][1];
        ans %= 9987;
        pos = po[pos][0];
    }

    printf("%d\n", ans);

    return 0;
}
