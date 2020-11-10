//
// Created by yangtao on 20-10-19.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
const int N = 705;
const int P = 1e9 + 7;
int n, match[N];
ll dp[N][N][3][3];
char s[N];
stack<int> st;
void dfs(int l, int r) {
    if(l + 1 == r) {
        dp[l][r][0][1] = dp[l][r][0][2] = dp[l][r][1][0] = dp[l][r][2][0] = 1;
    } else if (match[l] == r) {
        dfs(l+1, r-1);
        for(int i = 0 ; i <= 2; i++) {
            for(int j = 0;j <= 2; j ++) {
                if(j != 1) dp[l][r][0][1] = (dp[l][r][0][1] + dp[l+1][r-1][i][j]) % P;
                if(j != 2) dp[l][r][0][2] = (dp[l][r][0][2] + dp[l+1][r-1][i][j]) % P;
                if(i != 1) dp[l][r][1][0] = (dp[l][r][1][0] + dp[l+1][r-1][i][j]) % P;
                if(i != 2) dp[l][r][2][0] = (dp[l][r][2][0] + dp[l+1][r-1][i][j]) % P;

            }
        }
    } else {
        dfs(l , match[l]), dfs(match[l] + 1, r);
        for(int i = 0 ;i <= 2; i++) {
            for(int j = 0 ; j <= 2; j ++) {
                for(int p = 0 ; p <= 2; p++) {
                    for(int q = 0;q <= 2; q++) {
                        if((j == 1 && p == 1) || (j == 2 && p == 2)) continue;
                        dp[l][r][i][q] = (dp[l][r][i][q] + dp[l][match[l]][i][j] * dp[match[l]+1][r][p][q] ) % P;
                    }
                }
            }
        }
    }
}
int main() {
    scanf("%s",s);
    n = strlen(s);
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') st.push(i);
        else match[st.top()] = i, match[i] = st.top(), st.pop();
    }
    dfs(0, n - 1);
    ll ans = 0;
    for(int i = 0; i <= 2; i++) {
        for(int j = 0; j <= 2; j++)
            ans = (ans + dp[0][n-1][i][j]) % P;
    }
    cout << ans;
    return 0;
}
