//
// Created by yangtao on 19-8-12.
//

#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

#define MAXN 500
int dp1[MAXN][MAXN], dp2[MAXN][MAXN], s[MAXN];
int a[MAXN];
int main() {
    int n;
    cin >> n;
    memset(dp2, 0x3f, sizeof(dp2));
    for (int i = 1; i <= n ; ++i) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for(int i = 1; i <= n * 2; i++) {
        s[i] = s[i-1] + a[i];
        dp2[i][i] = a[i];
    }

    for (int k = 1; k <= n ; ++k) {
        for (int i = 1; i <= n * 2 - k + 1 ; ++i) {
            int e = i + k - 1;
            for (int j = i; j < e ; ++j) {
                dp1[i][e] = max(dp1[i][e],dp1[i][j]+dp1[j+1][e]+s[e]-s[i-1]);
                dp2[i][e] = min(dp2[i][e],dp2[i][j]+dp2[j+1][e]+s[e]-s[i-1]);
            }
            cout << dp1[i][e] << " " << dp2[i][e] << endl;
        }
    }
    int ans1 , ans2 = INT_MAX;
    for(int i = 1; i <= n; i++) {
        ans1 = max(ans1, dp1[i][i+n-1]);
        ans2 = min(ans2, dp2[i][i+n-1]);
    }
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}