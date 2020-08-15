//
// Created by yangtao on 20-8-8.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int v[N], w[N], f[N][N];
int n, V;
int main() {
    cin >> n >> V;
    for(int i = 1; i <= n ; i++) {
        scanf("%d%d", &v[i], &w[i]);
    }
    for(int i = 1; i <= n; i++ ) {
        for(int j = 1 ; j <= V; j++) {
            for (int k = 0; k * v[i] <= j; k++ )
                f[i][j] = max(f[i-1][j], f[i-1][j - k * v[i]] + k * w[i]);
        }
    }
    cout << f[n][V];
    return 0;
}
