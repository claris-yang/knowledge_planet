//
// Created by yangtao on 20-4-15.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 105, M = 10010;
int f[M];
int t,n,m;
int a[N][N];
int main() {
    cin >> t >> n >> m;
    for(int i = 1; i <= t; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 1; i < t; i++) {
        memset(f, 0, sizeof(f));
        for(int j = 1; j <= n; j++) {
            if(a[i+1][j] > a[i][j])
            for(int k = a[i][j] ; k <= m; k++) {
                f[k] = max(f[k], f[k-a[i][j]] + a[i+1][j] - a[i][j]);
            }
        }
        m += f[m];
    }

    cout << m << endl;
    return 0;
}