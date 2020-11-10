//
// Created by yangtao on 20-10-19.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 400000;
int s[500], f[500], dp[N<<1+5];
int n, ans;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", s + i, f + i);
    }

    memset(dp, -0x7f, sizeof(dp));
    dp[N] = 0;

    for(int i = 1;  i <= n; i++) {
        if(s[i] > 0) {
            for(int j = N << 1; j >= s[i]; j--) {
                dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
            }
        } else {
            for(int j = 0 ; j  <= (N << 1) + s[i]; j++) {
                dp[j] = max(dp[j], dp[j-s[i]] + f[i]);
            }
        }
    }
    for(int i = N ; i <= N << 1; i++) {
        if(dp[i] >= 0 ) ans = max(ans, i + dp[i] - N);
    }
    cout << ans;
    return 0;
}