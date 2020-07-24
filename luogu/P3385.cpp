//
// Created by yangtao on 19-11-13.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using  namespace std;
const int maxn = 2e3+5;
const int maxm = 2e3+5;
struct E {
    int u, v, w;
}edges[maxm<<1];
int dis[maxn];
int t, n, m, k;
int add (int a, int b) {
    if(a == 0x3f3f3f3f || b == 0x3f3f3f3f) return 0x3f3f3f3f;
    else return a + b;
}
int main()
{
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int i = 0, k = 0 ;
        memset(dis, 0x3f, sizeof(dis));
        memset(edges, 0, sizeof(edges));
        for(i = 0, k ; i < m; i++, k++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[k] = {u, v, w};
            if(w >= 0) {
                edges[++k] = {v, u, w};
            }
        }

        dis[1] = 0;
        bool flag = true;
        for(int i = 0; i < n; i++) {
            flag = true;
            for(int j = 0; j < k ; j++) {
                if( add(dis[edges[j].u], edges[j].w) < dis[edges[j].v]) {
                    dis[edges[j].v] = dis[edges[j].u] + edges[j].w;
                    flag = false;
                }
            }
            if(flag) break;
        }
        for (i = 0; i < k; ++i) {
            if( add(dis[edges[i].u], edges[i].w) < dis[edges[i].v]) {
                goto YES;
            }
        }

        puts("N0");
        continue;
        YES:
        puts("YE5");

    }


    return 0;
}