//
// Created by yangtao on 20-8-6.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 35;
int dp[N][N], a[N];
int n, m, t, ans;
int main() {
    cin >> n >> t >> m;
    for(int i = 1 ; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
            for( int k = t; k >= a[i]; k-- ) {
                dp[j][k] = max(dp[j][k], max(dp[j-1][t] + 1, dp[j][k-a[i]] + 1));
            }

        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <=t; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    printf("%d\n", ans);
    return 0;
}