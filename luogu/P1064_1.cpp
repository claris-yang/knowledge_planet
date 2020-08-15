//
// Created by yangtao on 20-8-15.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5e4;
struct Node {
    int v, w, q;
};
int f[N];
int n, m;
Node a[N];
vector<int> adj[65];

int main() {
    cin >> n >> m;
    for(int i = 1; i <=m; i++) {
        scanf("%d%d%d", &a[i].v, &a[i].w, &a[i].q);
        a[i].w *= a[i].v;
        if(a[i].q) {
            adj[a[i].q].push_back(i);
        }
    }
    int ans = 0;
    for( int i = 1; i <= m; i++ ) {
        if(a[i].q) continue;
        for(int j = n; j >= a[i].v; j--) {
            f[j] = max(f[j], f[j - a[i].v] + a[i].w);
            if(adj[i].size() >= 1) {
                int c = adj[i][0];
                if(j - a[i].v - a[c].v >= 0)
                    f[j] = max(f[j], f[j - a[i].v - a[c].v] + a[i].w + a[c].w);
            }
            if( adj[i].size() == 2 ) {
                int c1 = adj[i][0];
                int c2 = adj[i][1];
                if(j - a[i].v - a[c1].v - a[c2].v >= 0)
                    f[j] = max(f[j], f[j - a[i].v - a[c1].v - a[c2].v] + a[i].w + a[c1].w + a[c2].w);
            }
            ans = max(ans, f[j]);
        }
    }

    cout << ans;
    return 0;
}