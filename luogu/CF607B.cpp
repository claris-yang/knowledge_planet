//
// Created by yangtao on 20-9-24.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 505;
int n, f[N][N], a[N];
int main () {
    cin >> n;
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++) {
        f[i][i] = 1;
        cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
        f[i][i+1] = 1 + (a[i] != a[i+1]);
    }

    for(int len = 3; len <= n; len++) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (a[l] == a[r] ) f[l][r] = f[l+1][r-1];
            for( int k = l ; k + 1 <= r; k++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k+1][r]);
            }
        }
    }
    cout << f[1][n];
    return 0;
}
