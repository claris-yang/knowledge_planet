//
// Created by yangtao on 20-5-22.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e6;
typedef long  long ll;
bool c[N];
ll l, r;
int main() {
    while( scanf("%lld%lld", &l, &r)) {

        double logr = log(r) + 1;
        memset(c, 0, sizeof(c));
        for(ll i = 2; i < logr; i++ ) {

            if( c[i] ) continue;

            for(ll j = i * i ; j < logr; j+=i) {
                c[j] = true;
            }

            for(ll j = (l / i) * i ; j <= r; j+=i ) {
                if(i != j) c[j] = true;
            }

        }

        int lp = 0;
        for(ll i = l ; i <= r ; i++) {
            if(!c[i])  {
                lp = i;
                break;
            }
        }

        bool flag = false;
        ll mmin = 0, mmax = 0;
        ll mpos1, mpos2;
        ll bpos1, bpos2;
        memset(&mmin, 0x3f, sizeof(mmin));
        for(ll i = lp + 1; i <= r; i++) {
            if( !c[i] ) {
                flag = true;
                if(mmin > i - lp) {
                    mmin = i - lp;
                    mpos1 = lp;
                    mpos2 = i;
                }
                if(mmax < i - lp ) {
                    mmax = i - lp;
                    bpos1 = lp;
                    bpos2 = i;
                }
                lp = i;
            }
        }
        if(flag) {
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", mpos1, mpos2, bpos1, bpos2);
        } else {
            cout << "There are no adjacent primes." << endl;
        }
    }
    return 0;
}