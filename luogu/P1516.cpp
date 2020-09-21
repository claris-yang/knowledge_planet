//
// Created by yangtao on 20-9-8.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef  long long ll;
ll x, y, m, n, l, x1, y1, ans;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if( !b ) {
        x = 1, y = 0;
        return a;
    }

    ans = exgcd(b, a % b, x, y);

    ll z = x;
    x = y;
    y = z - (a / b) * y;
    return ans;
}

int main() {
    cin >> x >> y >> m >> n >> l;
    ll a, b;
    a = x - y, b = n - m;
    if( b < 0) {
        a -= a, b -= b;
    }
    exgcd(b, l, x1, y1);
    if(a % ans != 0 ) {
        cout<<"Impossible";
    } else {
        cout << ((x1 * (a / ans)) % (l/ans) + (l/ans)) % (l / ans);
    }
    return 0;
}
