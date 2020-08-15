//
// Created by yangtao on 20-8-15.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 405;
int f[N][N];
int n, u, v;

int main() {
    cin >> u >> v >> n;
    for(int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        for(int j = u; j >= x; j--) {
            for(int k = v; k >= y; k--) {
                f[j][k] = max(f[j][k], f[j-x][k-y] + z);
            }
        }
    }
    cout << f[u][v];
    return 0;
}