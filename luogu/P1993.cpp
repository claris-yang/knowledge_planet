//
// Created by yangtao on 19-11-13.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using  namespace std;
const int maxn = 1e5+5;
const int maxm = 1e5+5;
struct E {
    int u, v, w;
}edges[maxm<<1];
int dis[maxn];
int n, m;
int add (int a, int b) {
    if(a == 0x3f3f3f3f || b == 0x3f3f3f3f) return 0x3f3f3f3f;
    else return a + b;
}
int main()
{
    cin >> n >> m;
    int k = 0;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0 ;
    for(int i = 0; i < m; i++, k++) {
        int a;
        cin >> a ;
        if(a == 1) {
            cin >> edges[k].u >> edges[k].v >> edges[k].w;
        } else if( a == 2) {
            cin >> edges[k].u >> edges[k].v >> edges[k].w;
            edges[k].w =  -edges[k].w;
        } else {
            int u, v;
            cin >> u >> v;
            edges[k].u= u, edges[k].v=v, edges[k].w=0;
            edges[++k].u = v , edges[k].v = u, edges[k].w = 0;
        }
    }

    bool flag;
    for(int i = 0; i < n; i++) {
        flag = true;
        for(int j = 0 ; j < k; j++) {
            if(add(dis[edges[j].u] , edges[j].w ) < dis[edges[j].v]) {
                dis[edges[j].v] = add(dis[edges[j].u], edges[j].w);
                flag = false;
            }
        }
        if(flag) break;
    }

    flag = true;
    for(int i = 0; i < k; i++) {
        if(add(dis[edges[i].u], edges[i].w) < dis[edges[i].v]) {
            flag = false; break;
        }
    }

    if(flag)
        puts("Yes");
    else
        puts("No");

    return 0;
}