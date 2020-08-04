//
// Created by yangtao on 20-8-1.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2005;
int dp[N][N];
int n, m;
char s1[N], s2[N];
int main() {
    cin >> s1 + 1 >> s2 + 1;
    n = strlen(s1 + 1);
    m = strlen(s2 + 1);

    for(int i = 1; i <=n; i++) dp[i][0] = i;
    for(int i = 1; i <=m; i++) dp[0][i] = i;
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <=m ; j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1];
            } else  {
                int t = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = min(t, dp[i-1][j-1]) + 1;
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}