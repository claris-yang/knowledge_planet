//
// Created by yangtao on 20-6-2.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10005;
int h[N];
int n, m, k, ans, nn;
struct Node {
    int x, y, z;
    bool operator<(const Node node) const {
        return z < node.z;
    }
};
Node node[N];
void init() {
    for(int i = 1; i <= n; i++) h[i] = i;
}
int find(int x) {
    if(h[x] != x) h[x] = find(h[x]);
    return h[x];
}
void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y ) h[x] = h[y];
}


int main( ) {
    cin >> n >> m >> k;
    init();
    for(int i = 0 ;i < m; i++) {
        scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].z);
    }
    sort(node, node+m);
    for(int i = 0; i < m ; i++) {
        if( find(node[i].x) == find(node[i].y) ) {
            continue;
        }
        union_set(node[i].x, node[i].y);
        nn++;
        ans += node[i].z;
        if(nn == n - k) break;
    }
    if(nn != n - k) cout << "No Answer" << endl;
    else cout << ans << endl;
    return 0;
}