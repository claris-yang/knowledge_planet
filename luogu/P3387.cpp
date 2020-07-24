//
// Created by yangtao on 20-5-29.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int a[N][N];
int n, m;
int x1, y1, x2, y2;
int main() {
    cin >> n >> m;

    for(int i = 0 ;i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1 ; j <= x2; j++) {
            a[j][y1] += 1, a[j][y2+1] -= 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d ", a[i][j-1] + a[i][j]);
            a[i][j] += a[i][j-1];
        }
        cout << endl;
    }
    return 0;
}