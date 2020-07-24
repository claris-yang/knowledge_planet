//
// Created by yangtao on 20-6-1.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5005;
int a[N][N];
int n, r, res;
int main() {
    cin >> n >> r;
    for(int i = 1; i <= n; i++) {
        int x, y, v;
        scanf("%d%d%d", &x, &y , &v);
        a[x+1][y+1] = v;
    }
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
        }
    }


    for(int i = r; i < N; i++) {
        for(int j = r; j < N; j++) {
            int d = a[i][j] - a[i-r][j] - a[i][j-r] + a[i-r][j-r];
            res = max(res, d);
        }
    }
    cout << res << endl;
    return 0;
}