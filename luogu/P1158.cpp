//
// Created by yangtao on 20-8-15.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
int f[N];
struct Node {
    int d1, d2;
    bool operator<(const Node &node) const {
        return d1 < node.d1;
    }
} a[N];
int n, x1, y1, x2, y2;
int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i].d1 = (x - x1) * (x - x1) + (y - y1) * (y - y1);
        a[i].d2 = (x - x2) * (x - x2) + (y - y2) * (y - y2);
    }
    sort(a + 1, a + n + 1);
    int ans = 0x3f3f3f3f;
    for(int i = n; i >= 1; i--) {
        f[i] = max(f[i+1], a[i].d2);
        ans = min(ans, a[i].d1 + f[i+1]);
    }
    cout << ans;
    return 0;

}
