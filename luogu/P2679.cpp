//
// Created by yangtao on 20-8-8.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1005;
const int P = 1000000007;
int n, m, t;
char s1[N], s2[N];
int f[N][N], g[N][N];
int main() {
    cin >> n >> m >> t;
    cin >> s1 + 1 >> s2 + 1;
    g[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = min(m, i); j >= 1; j--) {
            for(int k = min(t, j); k >= 1; k--) {
                f[j][k]=s1[i]==s2[j] ? (f[j-1][k]+g[j-1][k-1]) % P : 0;
                g[j][k]=(g[j][k]+f[j][k])%P;
            }
        }
    }
    cout << g[m][t] << endl;
    return 0;
}
