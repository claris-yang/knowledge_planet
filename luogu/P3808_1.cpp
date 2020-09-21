//
// Created by yangtao on 20-9-11.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll n, m, p;
ll a[N];
ll pow(ll n, ll m, ll p) {
    ll res = 1;
    while(m) {
        if(m & 1) res = res * n % p;
        n = n * n % p;
        m >>= 1;
    }
    return res;
}
ll c(ll n, ll m, ll p) {
    if(m > n) return 0;
    return ((a[n] * pow(a[m], p-2, p) ) % p * pow(a[n-m], p-2, p) % p);

}
ll lucas(ll n, ll m, ll p) {
    if(!m) return 1;
    return c(n%p, m%p, p) * lucas(n/p, m/p, p) % p;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m >> p;
        a[0] = 1;
        for(int i = 1; i <= p ; i++) a[i] = (a[i-1] * i) % p;
        cout << lucas(n + m, n, p) << endl;
    }
    return 0;
}
