//
// Created by yangtao on 20-8-22.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std ;
const int N = 20;
int n, m;
int a[N][N];
int f[N][N], p[N][N], ans[N];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++ ) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k <= j ; k++) {
                if(f[i-1][j-k] + a[i][k] > f[i][j]) {
                    f[i][j] = f[i-1][j-k] + a[i][k];
                    p[i][j] =  k;
                }
            }
        }
    }
    cout << f[n][m] << endl;

    // 分配给第n个公司是p[n][m]台, 我们想知道第n-1家公司 那这个解通过p[n-1][m - p[n][m]]转化而来的
    for (int i = n; i >= 1; --i) {
        ans[i] = p[i][m];
        m -= ans[i];
    }
    for (int i = 1; i <= n; ++i) {
        cout << i << " " << ans[i] << endl;
    }
    return 0;
}

