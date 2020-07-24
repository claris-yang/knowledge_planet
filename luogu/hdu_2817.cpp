//
// Created by yangtao on 20-5-15.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N = 200907;
int n;
ll a[4];
bool isArith() {
    if(a[2] - a[1] == a[1] - a[0]) return true;
    else return false;
}
ll power(ll a, ll d) {
    ll res = 1;
    while(d) {
        if( d & 1) {
            res = (a * res) % N ;
        }
        a = (a * a) % N;
        d >>= 1;
    }
    return res;
}
int main() {
    cin >> n;
    while(n--) {
        for(int i = 0 ;i < 4; i++) {
            scanf("%lld", &a[i]);
        }
        if(isArith()) {
            printf("%lld\n", (a[0] % N + (a[3] - 1) * (a[1] - a[0]) % N) % N);
        } else if(a[0] == 0 ) {
            printf("0\n");
        }else{
            printf("%lld\n", a[0] % N *power(a[1] / a[0], a[3] - 1) % N);
        }
    }
    return 0;
}