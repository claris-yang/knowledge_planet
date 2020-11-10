//
// Created by yangtao on 20-9-25.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 250;
int f[N][N];
int n, ans ;
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> f[i][i];
    }

    for(int len = 2; len <= n; len++) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for(int k = l; k < r; k++) {
                if(f[l][k] == f[k+1][r] && f[l][k] && f[k+1][r]) {
                    f[l][r] = max(f[l][r], f[l][k] + 1);
                    ans = max(ans, f[l][k] + 1);
                }
            }
        }
    }
    cout << ans ;
    return 0;
}
