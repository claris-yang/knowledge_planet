//
// Created by yangtao on 20-8-21.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
int q[N], s[N], h[N], v[N], ans, n, top;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> h[i] >> v[i];
        while(top && h[q[top]] < h[i]) s[i] += v[q[top--]];
        s[q[top]] += v[i];
        q[++top] = i;
    }
    for(int i = 1; i <=n; i++) ans = max(ans, s[i]);
    cout << ans ;
    return 0;

}