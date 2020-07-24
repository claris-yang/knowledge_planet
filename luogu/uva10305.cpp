//
// Created by yangtao on 20-4-27.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 105;
int v[N][N];
int c[N], top[N];
int n, m, t;
bool dfs(int u ) {
    c[u] = -1;
    for(int i = 1 ; i <= n; i++) {
        if(v[u][i]) {
            if(c[i] < 0) return false;
            else if(!c[i] && !dfs(i)) return false;
        }
    }
    c[u] = 1, top[--t] = u;
    return true;
}

bool topsort() {
    t = n;
    for(int i = 1; i <= n; i++) {
        if( !c[i] && !dfs(i) ) return false;
    }
    return true;
}
int main() {
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x][y] = 1;
    }
    bool flat = topsort();

    if(flat) {
        for(int i = 0 ; i < n; i++) {
            printf("%d ", top[i]);
        }
    }
    return 0;
}

