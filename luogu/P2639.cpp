//
// Created by yangtao on 20-8-11.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 45005;
int f[N], v[N];
int n, m;
int main() {
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = m ; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + v[i]);
            ans = max(f[j], ans);
        }
    }
    cout << ans ;

    return 0;
}