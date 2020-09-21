//
// Created by yangtao on 20-8-25.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 50005;
int n, ans;
int f[N];
int main() {
    cin >> n;
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    ans = (n - 1) * ( n - 1);
    n--;
    for(int i= n; i >= 2; i--) {
        f[i] = (n / i ) * (n / i);
        for(int j = 2 * i; j <= n; j+= i) f[i] -= f[j];
        ans -= f[i];
    }
    printf("%d", ans + 2);
    return 0;
}
