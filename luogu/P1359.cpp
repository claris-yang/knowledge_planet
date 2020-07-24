//
// Created by yangtao on 20-4-17.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N =205;
int f[N], a[N][N];
int n;
int main() {
    cin >> n;
    memset(f, 0x3f, sizeof(f));

    for(int i = 1; i < n; i++) {
        for(int j = i+1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    f[1] = 0;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            f[i] = min(f[i], f[j] + a[j][i]);
        }
    }

    cout << f[n] << endl;
    return 0;
}