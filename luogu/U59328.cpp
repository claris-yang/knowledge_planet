//
// Created by yangtao on 20-9-14.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5;
int n , p, ans;
int t[N][N], m[N][N], res[N][N];

void mul() {
    memset(t, 0, sizeof(t));
    for(int i = 0 ; i < 2; i++) {
        for(int j = 0 ; j < 2; j++) {
            for(int k = 0 ; k < 2; k++) {
                t[i][j] = (t[i][j] + (m[i][k] * m[k][j] % p)) % p;
            }
        }
    }
    for(int i = 0 ; i < 2; i++) {
        for(int j = 0 ; j  <2; j++) {
            m[i][j] = t[i][j];
        }
    }
}


void result() {
    memset(t, 0, sizeof(t));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                t[i][j] = (t[i][j] + (res[i][k] * m[k][j] % p)) % p;
            }
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            res[i][j] = t[i][j];
        }
    }
}

void fast_pow(int k) {
    while(k) {
        if(k & 1) result();
        mul();
        k >>= 1;
    }
}
int fabi(int k) {
    if(k <= 2) return 1;
    k-=3;
    memset(res, 0, sizeof(res));
    memset(m, 0, sizeof(m));
    memset(t, 0, sizeof(t));
    res[0][0] = res[1][1] = m[0][1] = m[1][0] = m[1][1] = 1;
    fast_pow(k);
    memset(m, 0, sizeof(m));
    memset(t, 0, sizeof(t));
    m[0][0] = m[1][0] = 1;
    int r = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 1; j++) {
            for(int k = 0; k < 2; k++) {
                r = (r + (res[i][k] * m[k][j] % p)) % p;
            }
        }
    }
    return r;
}
int main() {
    cin >> n >> p;
    for(int i = 1; i <= n; i++) {
        cout << fabi(i) << endl;
        ans = (fabi(i) + ans) % p;
    }
    cout << ans;
    return 0;
}
