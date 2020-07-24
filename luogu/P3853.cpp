//
// Created by yangtao on 20-6-1.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 100005;
int l, r, len;
int n, d;
int a[N];
bool calc( int x ) {
    int p = 0;
    for(int i = 1; i < n; i++) {
        if( a[i] - a[i-1] > x  ) {
            // a[i] - a[i-1] - 1 减 1 是为了代码短一些
            // 实际 在 (a[i] - a[i-1]) % x == 0 的情况下 p += (a[i] - a[i-1]) / x - 1;
            p += (a[i] - a[i-1] - 1) / x;
        }
    }
    return p <= d;
}
int main() {
    cin >> len >> n >> d;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a , a + n);
    l = 0, r = len;
    while(l < r) {
        int mid = l + r >> 1;
        if( calc( mid ) ) r = mid ; else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
