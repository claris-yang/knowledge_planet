//
// Created by yangtao on 20-10-19.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1000005;
int n, a[N], c[N];
ll ans, avg;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        avg += a[i];
    }

    avg /= n;
    for(int i = 2; i <= n; i++) {
        c[i] = c[i-1] - avg + a[i];
    }

    sort(c + 1, c + n + 1);

    int mid = c[(n >> 1) + 1];

    for(int i = 1; i <= n; i++) {
        ans += abs(c[i] - mid);
    }
    cout << ans ;
    return 0;

}
