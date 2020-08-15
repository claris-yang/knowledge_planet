//
// Created by yangtao on 20-8-11.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=200010;
int m, f[N], s[N];
int main() {
    cin >> m;
    memset(f, 0x3f, sizeof(f));
    int n = ceil(sqrt(sqrt(m )) + 1);
    for(int i = 1; i <= n; i++) {
        s[i] = i * i * i * i;
    }
    f[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = s[i]; j <= m; j++) {
            f[j] = min(f[j], f[j - s[i]] + 1);
        }
    }
    cout << f[m];
    return 0;
}