//
// Created by yangtao on 19-10-30.
//

#include <iostream>
using namespace std;
const int N = 50;
int a[N], dp[N][N], g[N][N];
int n;
void print(int l, int r) {
    if(l > r) return ;
    int root = g[l][r];
    cout << root << ' ' ;
    print(l, root - 1);
    print(root+ 1, r);
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++ ) cin >> a[i];
    for(int len = 1; len <= n; len++) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if(l == r) {
                dp[l][r] = a[l];
                g[l][r] = l;
            } else {
                for(int k = l ; k <= r; k++) {
                    int lv = k == l ? 1 : dp[l][k-1];
                    int rv = k == r ? 1 : dp[k+1][r];
                    int score = lv * rv + a[k];
                    if(dp[l][r] < score) {
                        dp[l][r] = score;
                        g[l][r] = k;
                    }
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    print(1, n);
    return 0;
}
