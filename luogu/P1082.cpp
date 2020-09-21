//
// Created by yangtao on 20-9-8.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a, b, x, y;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if( b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll res = exgcd(b, a % b, x, y);
    ll z = x;
    x  = y , y = z - (a / b) * y;
    return res;
}
int main() {
    cin >> a >> b;
    exgcd(a, b, x, y);
    cout << (x + b) % b;
    return 0;
}