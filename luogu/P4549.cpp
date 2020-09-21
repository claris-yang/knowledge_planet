//
// Created by yangtao on 20-9-2.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int x,  ans, n;
int gcd(int x, int y) {
    return y ? gcd(y , x % y) : x;
}
int main( ) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x < 0) x = -x;
        ans = gcd(ans, x);
    }
    cout << ans ;
    return 0;
}
