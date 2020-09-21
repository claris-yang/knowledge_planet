//
// Created by yangtao on 20-9-14.
//

#include <algorithm>
#include <cstdio>
const int p = 1e9 + 7;
using  namespace std;
typedef long long ll;
const int N = 105;
int n;
ll k;
ll res[N][N], m[N][N], t[N][N];
void mul() {
    memset(t, 0, sizeof(t));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                t[i][j] = (t[i][j] + (m[i][k] * m[k][j] %p))% p;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            m[i][j] = t[i][j];
        }
    }
}

void result() {
    memset(t, 0, sizeof(t));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                t[i][j] = (t[i][j] + (res[i][k] * m[k][j] %p)) % p;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res[i][j] = t[i][j];
        }
    }
}

void fast( ll k ) {
    while(k > 0) {
        if(k & 1) {
            result();
        }
        mul();
        k = k >> 1;
    }
}

int main() {
    cin  >> k;
    n = 2;
    if ( k <= 2) {
        cout << 1;
        return 0;
    }
    k -= 3;
    res[1][1] = res[0][0] = m[0][1] = m[1][1] = m[1][0] = 1;
    fast(k);

    ll ans = 0;
    t[0][0] = t[1][0] = 1;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 1; j++) {
            for(int k = 0; k < 2; k++) {
                ans = (ans + (res[i][k] * t[k][j] % p)) % p;
            }
        }
    }
    cout << ans ;
    return 0;
}