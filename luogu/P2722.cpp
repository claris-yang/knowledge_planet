//
// Created by yangtao on 20-8-11.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std ;
const int N = 1e4 + 5;
int f[N], v[N], w[N];
int n, m;
int main() {
    cin >> m >> n;
    for(int i = 1; i <=n ; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = v[i]; j <= m; j++) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m];
    return 0;

}
