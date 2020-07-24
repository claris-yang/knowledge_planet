//
// Created by yangtao on 19-10-15.
//

#include <iostream>
using namespace std;
int dp[105][105];
int main() {
    int n, m, cmax = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int t;
            cin >> t;
            if(t == 1)
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1])) + 1;
            cmax = max(cmax, dp[i][j]);
        }
    }

    cout << cmax << endl;
    return 0;
}