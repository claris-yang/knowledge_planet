//
// Created by yangtao on 20-9-30.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int h[N], e[N*2] , ne[N*2];
int low[N], dfn[N], cut[N];
int n, m, idx, cnt;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void tarjan(int u, int fa) {

    dfn[u] = low[u] = ++cnt;
    int child = 0;
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if(!dfn[v]) {
            tarjan(v, fa);
            low[u] = min(low[u], low[v]);

            // 如果一个节点的根节点, 不是父节点的跟节点, 那么u节点是一个割点
            if( low[v] >= dfn[u] && u != fa ) {
                cut[u] = 1;
            }

            // 如果u是根节点, 计算子节点个数
            if(u == fa) {
                child++;
            }
        }
        low[u] = min(low[u], dfn[v]);
    }

    // 如果u是根节点, 并且孩子个数大于等于2的话, u是一个割点
    if(u == fa && child >= 2) {
        cut[u] = 1;
    }
}
int main( ) {
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }

    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) tarjan(i, i);
    }


    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(cut[i]) ans++;
    }

    cout << ans << endl;

    for(int i = 1; i <= n; i++) {
        if(cut[i]) printf("%d ", i);
    }

    return 0;

}

