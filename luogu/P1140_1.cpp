//
// Created by yangtao on 20-8-22.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 105;
char s1[N], s2[N];
int f[N][N];
int dict[5][5] = {
        {5, -1, -2, -1, -3},
        {-1, 5, -3, -2, -4},
        {-2, -3, 5, -2, -2},
        {-1, -2, -2, 5, -1},
        {-3, -4, -2, -1, -1000}
};
int pos(char c) {
    if (c == 'A') {
        return 0;
    } else if (c == 'C') {
        return 1;
    } else if (c  == 'G') {
        return 2;
    } else if (c == 'T') {
        return 3;
    } else {
        return 4;
    }
}
int l1, l2;
int main() {
    cin >> l1 >> s1 + 1 >> l2 >> s2 + 1;
    for(int i = 1; i <= l1; i++) {
        int x = pos(s1[i]);
        f[i][0] = f[i-1][0] + dict[x][4];
    }
    for(int i = 1; i <= l2; i++) {
        int x = pos(s2[i]);
        f[0][i] = f[0][i-1] + dict[4][x];
    }
    for(int i = 1; i <= l1; i++) {
        for(int j =1; j <= l2; j++) {
            int x = pos(s1[i]);
            int y = pos(s2[j]);
            int t = max(f[i-1][j] + dict[x][4], f[i][j-1] + dict[4][y]);
            f[i][j] = max(f[i-1][j-1] + dict[x][y], t);
        }
    }
    cout << f[l1][l2];
    return 0;
}