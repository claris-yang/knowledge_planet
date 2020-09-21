//
// Created by yangtao on 20-8-18.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 300005;
int n,l,r, ans;
int a[N], q[N], f[N];
int main() {
    cin >> n >> l >> r;
    for(int i = 0 ; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int h = 1, t = 1;
    memset(f, 0xcf, sizeof(f));
    ans = f[0];
    f[0]= 0;
    int p = 0;
    for(int i = l; i <= n; i++) {
        while(h <= t && f[q[t]] <= f[p]) {
            t--;
        }
        q[++t] = p;
        while(q[h] + r < i) {
            h++;
        }
        f[i] = f[q[h]] + a[i];
        p++;
    }
    for(int i = n + 1 -r ; i <= n; i++) {
        ans = max(ans, f[i]);
    }
    cout << ans ;

    return 0;
}