//
// Created by yangtao on 20-9-18.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1005;
int d[N][N], a[N][N];
int n, k;
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int x, y, x2, y2;
        scanf("%d%d%d%d", &x, &y, &x2, &y2);
        d[x+1][y+1] += 1;
        d[x+1][y2+1] -= 1;
        d[x2+1][y+1] -= 1;
        d[x2+1][y2+1] += 1;
    }

    int ans  = 0;
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];
            if(d[i][j] == k) ans++;
        }
    }
    cout << ans ;
    return 0;
}
