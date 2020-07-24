//
// Created by yangtao on 20-7-6.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
const int N = 1e5 + 5;
typedef long long ll;
using namespace std;
ll n, m, a[N];
double ans;
ll q[N], t, h;

double k(ll x, ll y) {
    return (double(a[x]) - a[y]) / (double(x) -y);
}
int main() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i] += a[i-1];
    }
    for(ll i = m; i <=n; i++) {
        while(t-h>=2 && k(i-m, q[t-1]) < k(i-m, q[t-2])) t--;
        q[t++] = i - m;
        while( t - h >= 2 && k(i, q[h]) < k(i, q[h+1])) h++;
        ans = max(ans, k(i, q[h]));
    }

    cout << (ll) floor(ans * 1000) << endl;
    return 0;
}