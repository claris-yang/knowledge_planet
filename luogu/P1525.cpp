//
// Created by yangtao on 20-5-21.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5e4 + 5;
struct Node {
    int x, y , z;
    bool operator<(const Node & s) const {
        return z > s.z;
    }
};
Node a[N * 2];
int n, m;
int f[N];
void init() {
    for(int i = 1; i <= n; i++) f[i] = i, f[i+n] = i + n;
}
int find(int x) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if( x != y ) f[x] = f[y];
}

int main() {
    cin >> n >> m ;
    init();
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    }
    sort(a + 1, a + m + 1);

    for(int i = 1; i <= m; i++) {
        if(find(a[i].x) == find(a[i].y)) {
            cout << a[i].z;
            return 0;
        } else {
            union_set(a[i].x, a[i].y+n);
            union_set(a[i].x + n, a[i].y);
        }

    }

    cout << 0 << endl;

    return 0;

}