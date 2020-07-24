//
// Created by yangtao on 19-12-4.
//


// 思路类似多重背包
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const int N = 105;
int dp[N];
int a[N];
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    dp[0] = 1;
    for(int i = 1; i <= n ;i++) {
        for(int j = m; j >= 0 ; j--) {
            for(int k = 1; j-k>=0 && k <= a[i]; k++) {
                // dp[m] 代表的是没有放第n个花盆的总放法
                // dp[m-k]  代表一次放一个放两个...的放法
                dp[j] = (dp[j] + dp[j-k] ) % 1000007;
            }
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}