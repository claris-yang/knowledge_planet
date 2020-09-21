//
// Created by yangtao on 20-9-8.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef  long long ll;

const int N = 20;
ll n, a[N], m[N], mi[N], mul =1, xx;
void exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1, y = 0;
        return ;
    }
    exgcd(b, a % b, x, y);
    ll z = x;
    x = y, y = z - y * (a/b);
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t >> a[i];
        m[i] = t;
        mul *= t;
    }
    for(int i = 1; i <= n; ++i) {
        mi[i] = mul / m[i];
        ll x = 0, y = 0;
        exgcd(mi[i], m[i], x, y);
        xx += a[i] * mi[i] * (x < 0 ? x + m[i] : x);
    }
    cout << xx * mul;
    return 0;
}