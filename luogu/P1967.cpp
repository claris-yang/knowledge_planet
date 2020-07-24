//
// Created by yangtao on 20-6-4.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e4 + 5;
int f[N], vis[N],  we[N][25], fa[N][25];
int e[N], ne[N], w[N], h[N], idx;
struct Node {
    int u, v, z;
    bool operator<(const Node &node) const {
        return z > node.z;
    }
}nodes[N];
int n, m, q, dep[N];
void init() {
    for(int i = 1; i <= n; i++) f[i] = i;
}

int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) f[x] = f[y];
}

void add(int u, int v, int z) {
    e[idx] = v, ne[idx] = h[u], w[idx] = z, h[u] = idx++;
}

void kruskal() {
    init();
    memset(h, - 1, sizeof(h));
    for(int i = 0 ;i < m; i++) {
        int u = find(nodes[i].u);
        int v = find(nodes[i].v);
        if(u != v) {
            merge(nodes[i].u, nodes[i].v);
            add(nodes[i].u, nodes[i].v, nodes[i].z);
            add(nodes[i].v, nodes[i].u, nodes[i].z);
        }
    }
}

void dfs(int b) {
    for(int i = h[b]; ~i; i = ne[i]) {
        int v = e[i];
        if(vis[v]) continue;
        vis[v] = 1;
        dep[v] = dep[b] + 1;
        fa[v][0] = b;
        cout << i << " -- " << w[i] << endl;
        we[v][0] = w[i];
        dfs(v);
    }
}

void pre() {
    for(int i = 1; i <= 20 ; i++) {
        for(int j = 1; j <= n; j++) {
            fa[j][i] = fa[fa[j][i-1]][i-1];
            we[j][i] = min(we[j][j-1], fa[fa[j][i-1]][i-1]);
        }
    }
}

int lca(int x, int y) {
    // 不连通
    if(find(x) != find(y)) return -1;

    if(dep[x] > dep[y]) {
        swap(x, y);
    }

    int ans = inf;
    for(int i = 20;i >= 0; i--) {
        if( dep[fa[y][i]] >= dep[x] ) {
            cout << "beijing " << i << " " << we[y][i] << endl;
            ans = min( ans, we[y][i] );
            y = fa[y][i];
        }
    }
    cout << ans << endl;
    if(x == y) return ans;
    for(int i = 20; i >= 0; i--) {
        if(fa[x][i] != fa[y][i]) {
            ans = min(ans, min(we[x][i], we[y][i]));
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    cout << ans << endl;
    ans = min(ans, min(we[x][0], we[y][0]));
    cout << ans << endl;
    return ans;
}

int main() {
    cin >> n >> m;
    for(int i = 0 ;i < m; i++ ) {
        scanf("%d%d%d", &nodes[i].u, &nodes[i].v, &nodes[i].z);
    }
    sort(nodes, nodes + m);
    kruskal();
    for(int i = 1; i <=n; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        dep[i] = 1;
        fa[i][0] = i;
        we[i][0] = inf;
        dfs(i);
    }
    pre();
    cin >> q;
    for(int i = 0 ;i < q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", lca(x, y));
    }
}

