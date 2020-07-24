//
// Created by yangtao on 20-5-22.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100005;
int f[N];
int n, m;
int cnt;
struct Node {
    int x, y, t;
    bool operator<(const Node &node) const {
        return t < node.t;
    }
};
Node node[N];
void init() {
    for(int i = 1; i <=n; i++) f[i] = i;
}
int find(int x) {
    if(f[x] != x ) f[x] = find(f[x]);
    return f[x];
}
void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y ) {
        f[x] = y;
        cnt--;
    }

}
int main() {
    cin >> n >> m;
    init();
    for(int i = 0 ; i < m; i++) {
        scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].t);
    }
    cnt = n;
    sort(node, node+m);
    int t = 0;
    if(cnt==1) {
        cout << 0 << endl;
        return 0;
    }
    for( int i = 0; i < m; i++ ) {
        t = node[i].t;
        union_set(node[i].x, node[i].y);
        if( cnt == 1 ) {
            cout << t << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
}