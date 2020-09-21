//
// Created by yangtao on 20-8-22.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2005;
int n, m, k;
char s1[N], s2[N];
int f[N][N];
int main()  {
    cin >> s1 + 1 >> s2 + 1 >> k;
    n = strlen(s1 + 1);
    m = strlen(s2 + 1);
    for(int i = 1; i <= n; i++) {
        f[i][0] = i * k;
    }
    for(int i = 1; i <= m; i++) {
        f[0][i] = i * k;
    }

    f[0][0] = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            f[i][j] = min(f[i-1][j-1] + abs(s1[i] - s2[j]) , f[i][j-1] + k);
        }
    }
    cout << f[n][m];
    return 0;
}