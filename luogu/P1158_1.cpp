//
// Created by yangtao on 20-8-22.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
struct Node {
    int dis1, dis2;
    bool operator<(const Node &node) const {
        return dis1 < node.dis1;
    }
};
int x1, y1, x2, y2;
int n;
Node a[N];
int  f[N];
int main( ) {
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i].dis1 = (x1 - x) * (x1 - x) + (y1 -y) * (y1 - y);
        a[i].dis2 = (x2 - x) * (x2 - x) + (y2 -y) * (y2 - y);
    }
    sort(a + 1, a + n + 1);
    int ans = 0x3f3f3f3f;
    for(int i = n; i >= 1; i--) {
        f[i] = max(f[i+1], a[i].dis2);
        ans = min(ans, f[i+1] + a[i].dis1);
    }

    cout << ans << endl;
    return 0;
}
