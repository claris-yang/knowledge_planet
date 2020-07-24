//
// Created by yangtao on 20-6-2.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100005;
int n, m, k, num, ans;

struct Node {
    int x, y, z;
    bool operator<(const Node &nn) const {
        return z > nn.z;
    }
};
Node node[N];
int f[N];
void init() {
    for(int i = 1; i <= n; i++) f[i] = i;
}
int find( int x ) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}
void union_set(int x, int y ) {
    x = find(x);
    y = find(y);
    if( x != y ) f[x] = f[y];
}
int main() {
    cin >> n >> m >> k;
    init();
    for(int i = 0 ; i< m; i++) {
        scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].z);
    }
    sort(node, node+m);
    for(int i = 0 ;i < m; i++) {
        if(find(node[i].x) == find(node[i].y)) continue;
        union_set(node[i].x, node[i].y);
        k--;
        ans += node[i].z;
        if(k == 0) break;
    }

    cout << ans << endl;
    return 0;
}