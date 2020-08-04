//
// Created by yangtao on 19-11-12.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 105;
int f[N][N];
int n, m;
char s1[N], s2[N];

int dict[5][5] = {
        { 5, -1, -2, -1, -3},
        {-1,  5, -3, -2, -4},
        {-2, -3,  5, -2, -2},
        {-1, -2, -2,  5, -1},
        {-3, -4, -2, -1 , -1000}
};
int d1[N], d2[N];

int tonum(char c) {
    if( c == 'A' )
        return 0;
    if( c == 'C' )
        return 1;
    if( c == 'G' )
        return 2;
    if( c == 'T' )
        return 3;
    if( c == '-' )
        return 4;
}
int main() {
    cin >> n >> s1 + 1;
    cin >> m >> s2 + 1;

    for(int i = 1; i <=n; i++) {
        d1[i] = tonum(s1[i]);
    }

    for(int i = 1; i <=m; i++) {
        d2[i] = tonum(s2[i]);
    }

    for(int i = 1; i <= n; i++) {
        f[i][0] = f[i-1][0] + dict[d1[i]][4];
    }

    for(int i = 1; i <= m; i++) {
        f[0][i] = f[0][i-1] + dict[4][d2[i]];
    }

    for(int i = 1 ; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int x = tonum(s1[i]);
            int y = tonum(s2[j]);
            f[i][j] = max(f[i-1][j] + dict[x][4], f[i][j-1] + dict[y][4]);
            f[i][j] = max(f[i][j], f[i-1][j-1] + dict[x][y]);
        }
    }
    cout << f[n][m];
    return 0;
}
