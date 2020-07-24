//
// Created by yangtao on 20-5-15.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll P = 10;
ll power(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % P;
        a = (a * a) % P;
        b >>= 1;
    }
    return res;
}
ll n, a;
int main() {
    cin >> n;
    while(n--) {
        scanf("%lld", &a);
        printf("%lld\n", power(a, a));
    }
    return 0;
}
