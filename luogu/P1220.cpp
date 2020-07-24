//
// Created by yangtao on 19-11-12.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100;
int n, c, a[N], s[N];
int dp[N][N][2];
int main() {
    cin >> n >> c;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i<=n; i++) {
        cin >> a[i] >> s[i];
        s[i] += s[i-1];
    }
    dp[c][c][0] = dp[c][c][1] = 0;
    for(int l = 2 ; l <= n; l ++) {
        for(int i = 1; i + l -1 <= n; i++) {
            int j = i + l - 1;
            dp[i][j][0] = min( dp[i+1][j][0] + (a[i+1] - a[i]) * (s[n] - s[j] + s[i]) , dp[i+1][j][1] + (a[j] - a[i]) * (s[n] - s[j] + s[i]));
            dp[i][j][1] = min( dp[i][j-1][1] + (a[j] - a[j-1]) * (s[n] - s[j-1] + s[i-1]) , dp[i][j-1][0] + (a[j] - a[i]) * (s[n] - s[j-1] + s[i-1]));
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]);
    return 0;
}