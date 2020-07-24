//
// Created by yangtao on 20-5-25.
//

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a, b, p;
ll mul(ll a, ll b, ll p) {
    ll res = 0;
    while(b > 0) {
        if(b & 1) res = (res + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    return res;
}
int main() {
    cin >> a >> b >> p;
    cout << mul(a, b, p) << endl;
    return 0;
}