//
// Created by yangtao on 20-7-31.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5005;
const int P = 100000000;
int f[2][N], r[2][N];
char s1[N], s2[N];
int n, m;
int main() {
    cin >> s1 + 1;
    cin >> s2 + 1;
    n = strlen(s1 + 1) - 1;
    m = strlen(s2 + 1) - 1;

    for(int k = 0; k <= m; k++)
        r[0][k] = 1;
    r[1][0] = 1;
    int now = 1, pre = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            f[now][j] = max(f[pre][j], f[now][j-1]);
            r[now][j] = 0; // 因为重复使用,相当于初始化了
            if( s1[i] == s2[j]) {
                f[now][j] = f[pre][j-1] + 1;
            }

            if( s1[i] == s2[j] && f[now][j] == f[pre][j-1] + 1)
                r[now][j] += r[pre][j-1];

            if( f[pre][j] == f[now][j] ) r[now][j] += r[pre][j];
            if( f[now][j-1] == f[now][j] ) r[now][j] += r[now][j-1];
            if( f[pre][j-1] == f[now][j] ) r[now][j] -= r[pre][j-1];
            r[now][j] %= P;

        }
        now = pre, pre = 1 - pre;
    }

    printf("%d\n%d", f[pre][m], r[pre][m]);
    return 0;
}