//
// Created by yangtao on 20-6-30.
//
#include <iostream>

#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5 + 5;
int e[N], ne[N], h[N], val[N], dis[N];
int n, idx, ans;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u],  h[u] = idx++;
}

void dfs( int x ) {
    if(dis[x]) ;
    dis[x] += val[x];
    for(int i = h[x]; ~i; i = ne[i] ) {
        int v = e[i];
        if( !dis[v] ) {
            dfs(v);
        }
        dis[x] = max(dis[x], val[x] + dis[v]);
    }
}

int main() {

    memset(h, -1, sizeof(h));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u;
        scanf("%d%d", &u, &val[i]);
        while(1) {
            int v;
            scanf("%d", &v);
            if(!v) break;
            add(u, v);
        }
    }

    for(int i = 1; i <=n; i++) {
        dfs(i);
        ans = max(ans, dis[i]);
    }

    cout << ans << endl;
    return 0;

}
