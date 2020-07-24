//
// Created by yangtao on 19-12-9.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 2505;
int a[N][N], dp[N][N];
int dp1[N][N]; // 记录行的DP
int dp2[N][N]; // 记录列切
int n, m;

void init() {
    memset(dp, 0x3f, sizeof(dp));
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));

    // 初始化
    for(int i = 0; i <=n; i++) {
        dp[i][0] = 0;
        dp[i][m+1] = 0;
    }
    for(int i = 0; i <=m + 1; i++) {
        dp[0][i] = 0;
    }

}
int main() {

    cin >> n >> m;
    for(int i = 1 ; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int ans = 0;

    // 对角线
    init();
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <=m; j++) {
            if(a[i][j] == 1 ) {
                dp[i][j] = min(min(dp1[i][j-1], dp2[i-1][j]), dp[i-1][j-1]) + 1;
                dp1[i][j] = dp2[i][j] = 0;
            } else {
                dp[i][j] = 0;
                dp1[i][j] += dp1[i][j-1] + 1;
                dp2[i][j] += dp2[i-1][j] + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    // 斜对角线
    init();
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
            if(a[i][j] == 1 ) {
                dp[i][j] = min(min(dp1[i][j+1], dp2[i-1][j]), dp[i-1][j+1]) + 1;
                dp1[i][j] = dp2[i][j] = 0;
            } else {
                dp[i][j] = 0;
                dp1[i][j] += dp1[i][j+1] + 1;
                dp2[i][j] += dp2[i-1][j] + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}