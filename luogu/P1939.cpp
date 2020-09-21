//
// Created by yangtao on 20-9-14.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int P = 1e9 + 7;
const int N = 5;
ll t[N][N], res[N][N], m[N][N];
int n = 3;

void mul() {
    memset(t, 0, sizeof(t));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                t[i][j] = (t[i][j] + m[i][k] * m[k][j] % P) % P;
            }
        }
    }
    for(int i = 0; i <= n; i++ ) {
        for(int j = 0; j <= n; j++) {
            m[i][j] = t[i][j];
        }
    }
}

void result() {
    memset(t, 0, sizeof(t));
    for(int i = 0 ; i < n; i++) {
        for(int j = 0 ; j < n; j++) {
            for(int k = 0; k < n; k++) {
                t[i][j] = (t[i][j] + (m[i][k] * res[k][j] % P)) % P;
            }
        }
    }
    for(int i = 0 ; i <= n; i++ ) {
        for(int j = 0 ;j <=n; j++) {
            res[i][j] = t[i][j];
        }
    }
}
void pow( int k ) {
    while(k) {
        if(k & 1) result();
        mul();
        k>>=1;
    }
}
int main() {
    int c;
    cin >> c;
    while(c--) {
        int k ;
        cin >> k;
        if(k <= 3) {
            cout << 1 << endl;
            continue;
        };
        k-=3;
        memset(res, 0, sizeof(res));
        memset(m, 0, sizeof(m));
        res[0][0] = res[1][1] = res[2][2] = 1;
        m[0][1] = m[1][2] = m[2][0] = m[2][2] = 1;
        pow(k);

        memset(t, 0, sizeof(t));
        memset(m, 0, sizeof(m));
        m[0][0] = m[1][0] = m[2][0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 1; j++) {
                for(int k = 0; k < n; k++) {
                    t[i][j] = (t[i][j] + res[i][k] * m[k][j] % P) % P;
                }
            }
        }
        cout << t[2][0] << endl;
    }
    return 0;
}
