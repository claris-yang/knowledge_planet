//
// Created by yangtao on 19-10-15.
//

#include <iostream>
#define MAXN 205
using namespace std;
int dp[MAXN][MAXN];

int main() {
    int m, n, t, res = 0;
    cin >> m >> n;
    for(int i = 1; i <= m ; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> t;
            dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1])) + t;
        }
    }

    res = max(max(dp[m][n/2], dp[m][n/2+2]), dp[m][n/2+1]);

    cout << res << endl;
    return 0;
}