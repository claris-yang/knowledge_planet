//
// Created by yangtao on 20-6-28.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5005;
int a[N][N];
int n, r, ans;
int main() {

    cin >> n >> r;

    for(int i = 0 ;i < n; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x+1][y+1] = z;
    }

    for(int i = 1;i <N; i++) {
        for(int j = 1; j < N; j++) {
            a[i][j] = a[i-1][j] + a[i][j-1]-a[i-1][j-1]+a[i][j];
        }
    }
    for(int i = r; i < N; i++) {
        for(int j = r; j < N; j++) {
            ans = max(ans, a[i][j] - a[i-r][j] - a[i][j-r] + a[i-r][j-r]);
        }
    }

    cout << ans ;

    return 0;

}