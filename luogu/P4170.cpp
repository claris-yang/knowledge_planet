//
// Created by yangtao on 20-7-10.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 55;
int f[N][N];
char s[N], n;
int main() {
    cin >> s + 1;
    int n = strlen(s+1);
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++) f[i][i] = 1;

    for(int len = 2; len <= n; len++) {
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len -1;
            if(s[i] == s[j] ) {
                f[i][j] = min(f[i+1][j], f[i][j-1]);
            } else {
                for(int k = i ; k + 1 <= j; k++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k+1][j]);
                }
            }

        }
    }
    cout << f[1][n] << endl;
    return 0;
}