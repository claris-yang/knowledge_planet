//
// Created by yangtao on 20-9-30.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e3 + 5;
int bucket[N], a[N][N], c[N];
int n, m, k;
int main() {
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for(int j = 1; j <= m; j++) {
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i++) {
            if(!c[a[i][j]]) {
                c[a[i][j]] = 1;
                bucket[a[i][j]]++;
            }
        }
    }
    for(int i = 1; i <=k; i++) {
        printf("%d " , bucket[i]);
    }
    return 0;
}