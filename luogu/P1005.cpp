//
// Created by yangtao on 20-9-24.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[50][50];
int n, m;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    }

    for(int l = 1; l <= m; l++) {
        for(int i = m; i >= l; i++) {
            f[l][i] = max(f[l][i] ,  f[l-1][i])
        }
    }
}

