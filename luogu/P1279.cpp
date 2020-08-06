//
// Created by yangtao on 20-8-6.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2005;
char s1[N], s2[N];
int k, n, m;
int dp[N][N];
int main() {
    cin >> s1 + 1 >> s2 + 1 >> k;
    n = strlen(s1 + 1);
    m = strlen(s2 + 1);
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n ; i++) {
        dp[i][0] = i * k;
    }
    for(int i = 1; i <= m ; i++ ) {
        dp[0][i] = i * k;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=m; j++) {
            int mm = min(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = min(mm + k, dp[i-1][j-1] + abs(s1[i] - s2[j]));
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}