//
// Created by yangtao on 19-10-30.
//

#include <iostream>
using namespace std;
const int N = 100;
int m, n;
int a[N][N], dp[N+N][N][N];
int main () {
    cin >> m >> n;
    for(int i = 1 ; i <= m; i++) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    for(int k = 2; k <= m+n; k++) {
        for(int x1 = max(1, k-n); x1 <= min(m, k-1); x1++) {
            for( int x2 = max(1, k-n); x2 <= min(m, k-1); x2++) {
                int t = a[x1][k-x1];
                if(x1 != x2) t += a[x2][k-x2];
                for(int i = 0; i <= 1; i++) {
                    for(int j = 0; j <= 1; j++) {
                        dp[k][x1][x2] = max(dp[k][x1][x2], dp[k-1][x1-i][x2-j] + t );
                    }
                }
            }

        }
    }

    cout << dp[m+n][m][m];
    return 0;
}
