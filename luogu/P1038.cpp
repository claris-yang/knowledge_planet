//
// Created by yangtao on 19-10-29.
//
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N = 105, M = N * N;

int e[M], ne[M], w[M], h[N], idx;
int din[N], dout[N];
int f[N], u[N];
int n, m;
int q[N];
void add(int a, int b, int c ) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void topsort() {
    int hh = 0, tt = -1;
    for(int i = 1; i <= n; i++) {
        if(!din[i]) {
            q[++tt] = i;
        }
    }
    while(hh <= tt) {
        int t = q[hh++];
        for(int i = h[t]; ~i; i = ne[i] ) {
            int j = e[i];
            if( --din[j] == 0 ) {
                q[ ++tt ] = j;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> f[i] >> u[i];
    memset(h,  -1, sizeof(h));
    for(int i = 0 ;i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        din[a]++, dout[b]++;
    }
    for(int i = 1; i  <= n; i++) {
        if(din[i])
            f[i] -= u[i];
    }
    topsort();
    for(int i= 0 ;i < n; i++) {
        int j = q[i];
        if(f[j] > 0 )
            for(int k = h[j]; ~k; k = ne[k])
                f[e[k]] += f[j] * w[k];
    }

    bool has_print = false;
    for(int i = 1; i <= n; i++) {
        if(!dout[i] && f[i] > 0) {

            cout << i << ' ' << f[i] << endl;
            has_print = true;
        }
    }
    if(!has_print) {
        cout <<  "NULL" << endl;
    }

    return 0;
}
