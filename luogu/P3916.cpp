
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;

int e[N], ne[N], h[N], vis[N];
int n,m , idx;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
void dfs(int x, int f) {
    vis[x] = f;
    for(int i = h[x]; ~i; i = ne[i]) {
        int v = e[i];
        if(vis[v]) continue;
        vis[v] = f;
        dfs(v, f);
    }
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for(int i = 0 ; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(v, u);
    }
    for(int i =  n; i >= 1; i--) {

        if( !vis[i] )
            dfs(i, i);
    }

    for(int i = 1; i <= n; i++) {
        printf("%d ", vis[i]);
    }
    return 0;
}