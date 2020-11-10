//
// Created by yangtao on 20-10-10.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 125;
int a[N][N], sum[N][N];
int n;
int main() {
    cin >> n;
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <= n ; j++ ) {
            scanf("%d", &sum[i][j]);
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }

    int ans;
    memset(&ans, -0x3f, sizeof(ans));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=n; j++) {
            for(int x = 1; x <= i ; x++) {
                for(int y = 1; y <= j ; y++) {
                    ans = max(ans, sum[i][j] - sum[x-1][j] - sum[i][y-1] + sum[x-1][y-1]);
                }
            }
        }
    }
    cout << ans ;
    return 0;
}
