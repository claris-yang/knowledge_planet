//
// Created by yangtao on 20-6-3.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e4 + 5;
int f[N];
int n, m, s, t;
struct Node {
    int x, y, z;
    bool operator<(const Node &nn) const {
        return z < nn.z;
    }
};
Node node[N];
void init() {
    for(int i = 1; i <= n; i++) f[i] = i;
}
int find(int x ) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}
void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) f[x] = f[y];
}
int main() {
    cin >> n >>  m >> s >> t;
    init() ;
    for(int i = 0 ; i < m; i++) {
        scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].z);
    }
    sort(node, node+m);
    for(int i = 0; i < m; i++) {
        if(find(node[i].x) == find(node[i].y)) continue ;
        union_set(node[i].x, node[i].y);
        if(find(s) == find(t)) {
            cout << node[i].z << endl;
            break;
        }
    }
    return 0;
}
