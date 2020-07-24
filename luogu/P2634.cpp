//
// Created by yangtao on 20-1-7.
//

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 20005;
int idx, rt, sum, cnt, ans , n;
int h[N<<1], to[N<<1], nt[N<<1], w[N<<1];
int siz[N], dis[N], maxp[N];
bool vis[N];
int tmp[5];

int gcd(int x, int y) {return (y?gcd(y, x%y) :x);}
void add(int u, int v, int ww) {
    to[idx] = v, w[idx] = ww, nt[idx] = h[u], h[u] = idx++;
}

void getrt(int u, int f) {

    siz[u] = 1, maxp[u] = 0;
    for(int i = h[u]; ~i; i = nt[i]) {
        int v = to[i];
        if( v == f || vis[v]) continue;
        getrt(v, u);
        siz[u] += siz[v];
        if( siz[v] > maxp[u] ) maxp[u] = siz[v];
    }
    maxp[u] = max(maxp[u],sum - siz[u]);
    if(maxp[u] < maxp[rt]) rt = u;

}

void getdis(int u, int f) {
    tmp[dis[u]]++;
    for(int i = h[u]; ~i; i = nt[i]) {
        int v = to[i];
        if(v == f || vis[v]) continue;
        dis[v] = (dis[u] + w[i]) % 3;
        getdis(v, u);
    }
}

int solve(int u, int d) {
    dis[u] = d % 3; tmp[0] = tmp[1] = tmp[2] = 0;
    getdis(u, 0);
    return tmp[1]*tmp[2]*2 + tmp[0]*tmp[0];
}
void divide(int u){
    vis[u]  = true;
    ans += solve(u, 0);
    for(int i = h[u]; ~i; i = nt[i]) {
        int v = to[i];
        if(vis[v] == true) continue;
        ans-=solve(v, w[i]);
        rt = 0, sum = siz[v];
        getrt(v, 0);
        getrt(rt, 0);
        divide(rt);
    }
}

int main() {

    memset(h, -1, sizeof(h));
    cin >> n ;
    for(int i = 1; i < n; i++ ) {
        int u, v , ww;
        scanf("%d%d%d", &u, &v, &ww);
        add(u, v, ww);
        add(v, u, ww);
    }

    maxp[0] = sum = n ;
    getrt(1, 0);
    getrt(rt, 0);
    divide(rt);

    int div = gcd(n*n, ans);
    printf("%d/%d", ans/div, n*n/div);

    return 0;
}