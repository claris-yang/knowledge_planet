//
// Created by yangtao on 20-7-9.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2005;
const int P = 19650827;
int a[N];
int f[N][N][2];
int n ;
int main() {
    cin >> n;
    for(int i = 1;i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) f[i][i][0] = 1;
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if(a[i] < a[i+1]) f[i][j][0] += f[i+1][j][0] % P ;
            if(a[i] < a[j])   f[i][j][0] += f[i+1][j][1] % P ;
            if(a[j] > a[j-1]) f[i][j][1] += f[i][j-1][1] % P ;
            if(a[j] > a[i])   f[i][j][1] += f[i][j-1][0] % P ;
        }
    }

    cout << (f[1][n][0] + f[1][n][1]) % P << endl;

    return 0;
}
