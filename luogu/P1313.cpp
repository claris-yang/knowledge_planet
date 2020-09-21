//
// Created by yangtao on 20-9-10.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int P = 10007;
ll a, b, k, n , m;

ll pow(ll n) {
    ll res = 1;
    for(int i = 1; i <= n; i++) {
        res = res * i % P;
    }
    return res;
}
int main() {
    cin >> a >> b >> k >> n >> m;
    ll ans1 = pow(k);
    ll ans2 = pow(k-m);
    ll ans3 = pow(m);
    cout << (ans1 * a * b % P ) / ans2 / ans3 ;
    return 0;
}