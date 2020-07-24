//
// Created by yangtao on 20-5-29.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int a[N][N];
int n, m, c;
int res, x, y;
int main() {
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            a[i][j] = a[i-1][j] + a[i][j-1] + a[i][j] - a[i-1][j-1];
        }
    }

    res = 0 - 0x3f3f3f3f;
    for(int i = 1; i + c - 1 <= n ; i++) {
        for(int j = 1; j + c - 1<= m; j++) {
            int s = a[i+c-1][j+c-1]-a[i+c-1][j-1]-a[i-1][j+c-1]+a[i-1][j-1];
            if ( s > res) {
                res = s, x = i, y = j;
            }
        }
    }
    cout << x << " " << y;
    return 0;
}