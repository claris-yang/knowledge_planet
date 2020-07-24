//
// Created by yangtao on 20-6-3.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1000005;
int p[N], v[N],f[N];
int n, m, l, r;
int main() {
    cin >> n >> m;
    l = 1, r = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for(int i = 1; i <= n; i++) {
        while( i >= p[l] + m && l <= r) l++;
        while( v[i] < v[p[r]] && l <= r) r--;
        p[++r] = i;
        f[i] = v[p[l]];
    }
    for( int i = m; i  <= n; i++) {
        printf("%d\n", f[i]);
    }
    return 0;
}