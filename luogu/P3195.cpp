//
// Created by yangtao on 20-7-6.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5;
typedef long long ll;
ll n, a[N], q[N], dp[N], l, h= 1, t;
ll X( ll j) {
    return a[j];
}
ll Y( ll j) {
    return dp[j] + (a[j] + l) * (a[j] + l);
}
double k(ll x, ll y) {
    return (double(Y(x)) - Y(y)) / (X(x) - X(y));
}
int main() {
    cin >> n >> l; ++l;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i] += a[i-1] + 1;
    }
    q[++t] = 0;
    for(int i = 1, j = 0; i <= n; i++) {
        while(h < t && k(q[h], q[h+1]) <= 2 * a[i]) ++h;
        dp[i] = dp[j = q[h]] + (a[i] - a[j] - l) * (a[i] - a[j] - l);
        while(h < t && k(q[t-1], q[t]) >= k(q[t-1], i)) --t;
        q[++t] = i;
    }
    cout << dp[n];

}