//
// Created by yangtao on 20-5-27.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 21;
int c[ N][N];
int n;
int f[1 << N][N];
int main() {
    memset(f, 0x3f, sizeof(f));
    cin >> n;
    for(int i = 0; i <n; i++) {
        for(int j = 0; j <n; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    f[1][0] = 0;
    for(int i = 1; i < 1 << n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >> j & 1 ) {
                for(int k = 0; k < n; k++) {
                    if( (i ^ 1 << j) >> k & 1 )
                    f[i][j] = min(f[i][j], f[i^1<<j][k] + c[k][j]);
                }
            }
        }
    }
    cout << f[ (1 << n) - 1][n-1];
    return 0;
}