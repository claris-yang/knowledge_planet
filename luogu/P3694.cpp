//
// Created by yangtao on 20-9-28.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 21;
const int N = 1e5 + 10;
int n, m;
int a[N], num[M], sum[N][M];
int f[(1<<M)];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 1; i <= n; i++) {
        num[a[i]]++;
        for(int j = 1; j <=m; j++) {
            sum[i][j] = sum[i-1][j];
        }
        sum[i][a[i]]++;
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for(int i = 1; i < ( 1 << m) ; i++) {
        int len = 0;
        for(int j = 1; j <= m; ++j) {
            if(i & (1 << (j - 1))) {
                len += num[j];
            }
        }
        for(int j = 1; j <=m; j++) {
            if( i & (1 << (j - 1))) {
                f[i] = min(f[i], f[i ^ (1 << (j - 1))] + num[j] - sum[len][j] + sum[len - num[j]][j]);
            }
        }
    }
    cout << f[(1 << m) - 1] ;
    return 0;

}
