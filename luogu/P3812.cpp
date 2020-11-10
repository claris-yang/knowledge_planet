//
// Created by yangtao on 20-10-24.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 60;
int n;
ll x, a[N+1], tmp[N+1];
bool flag;
void ins(ll x) {
    for(int i = N; ~i; i--) {
        if(x & (1ll << i)) {
            if (!a[i]) {
                a[i] = x;
                return ;
            } else {
                x^=a[i];
            }
        }
    }
    flag = true;
}
ll qmax() {
    ll res = 0;
    for (int i = N; ~i ; i--) {
        res = max(res, res^a[i]);
    }
    return res;
}

ll qmin() {
    if(flag) return 0;
    for(int i = 0; i <= N; i++) {
        if(a[i]) {
            return a[i];
        }
    }
}

ll query(ll k) {
    ll res = 0; int cnt = 0;
    k-=flag;
    if(!k) return 0;
    for(int i = 0; i <= n; i++) {
        for(int j = i - 1; ~j ; j--) {
            if(a[i] & (1ll << j)) a[i]^=a[j];
        }
        if(a[i]) tmp[cnt++] = a[i];
    }
    if(k >= (1ll << cnt)) return -1;
    for(int i = 0; i < cnt; i++) {
        if( k & (1ll << i)) res ^= tmp[i];
    }
    return res;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &x), ins(x);
    }
    printf("%lld\n", qmax());
    return 0;
}
