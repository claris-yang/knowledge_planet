//
// Created by yangtao on 20-8-3.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int n, int m) {
    if(n % m == 0) return m;
    return gcd(m, n % m);
}
int n, m;
int ans;
int main() {
    cin >> m >> n;
    if(n == m) ans--;
    n *= m;
    for(int i = 2; i * i <= n ; i++) {
        if( n % i == 0 && gcd(i , n / i) == m) {
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}