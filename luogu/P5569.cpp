//
// Created by yangtao on 19-11-12.
//

#include <iostream>
#include <cstring>
using namespace std;
int dp[205][205];
int n;
int sum[205];
int main() {
    cin >> n;
    for(int i = 0 ;i < n; i++) {
        cin >> dp[i][i];
        dp[i+n][i+n] = dp[i][i];
    }

    for(int i = 1; i < n * 2; i++) {
        sum[i] = sum[i-1] + dp[i][i];
    }

    for(int l = 1; l < n ; l++) {
        for(int i = 0; i + l < n * 2 - 1; i++) {
            int j = i + l;
            for(int k = i; k < j ; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j]-sum[i-1]);
            }
        }
    }

    for(int i = 0 ;i < 8; i++) {
        for(int j = 0; j < 8; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }

    int ans = 0;
    for( int i = 0; i < n ;i++) {
        ans = max(ans, dp[0][i+n]);
    }

    cout << ans << endl;

    memset(dp, 0x3f, sizeof(dp));

    for(int l = 1; l < n ; l++) {
        for(int i = 0; i + l < n; i++) {
            int j = i + l;
            for(int k = 0; k <= i ; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    cout << dp[n-1][n-1];
    return 0;
}