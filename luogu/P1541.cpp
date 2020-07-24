//
// Created by yangtao on 20-4-14.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 360, M = 45;
int a[N];
int n, m;
int b[5];
int f[M][M][M][M];
int main() {
    cin >> n  >> m;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(int j = 1; j <= m; j++) {
        int t;
        scanf("%d", &t);
        b[t]++;
    }

    for(int A = 0 ; A <= b[1]; A++) {
        for(int B = 0; B <= b[2]; B++) {
            for(int C = 0; C <= b[3]; C++) {
                for(int D = 0; D <= b[4]; D++) {
                    int t = A + B * 2 + C * 3 + D * 4;
                    int &tot = f[A][B][C][D];
                    if( A > 0 ) tot = max(tot, f[A-1][B][C][D] + a[t]);
                    if( B > 0 ) tot = max(tot, f[A][B-1][C][D] + a[t]);
                    if( C > 0 ) tot = max(tot, f[A][B][C-1][D] + a[t]);
                    if( D > 0 ) tot = max(tot, f[A][B][C][D-1] + a[t]);
                }
            }
        }
    }

    cout << f[b[1]][b[2]][b[3]][b[4]]+a[0] << endl;

    return 0;
}