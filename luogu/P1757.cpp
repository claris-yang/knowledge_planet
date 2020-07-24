//
// Created by yangtao on 20-4-13.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1005;
int f [N] ;
int v[N], w[N];
int n, m;
int pc, pn;
int main() {
    cin >> m >> n;
    for(int i = 1; i <=n ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(c != pc) {
            for(int j = m; j >= 0; j--) {
                for(int k = 0; k <= pn; k++) {
                    if(j >= v[k]) f[j] = max(f[j], f[j - v[k]] + w[k]);
                }
            }
            pn = 0;
        } else {
            pn++;
        }
        v[pn] = a, w[pn] = b;
        pc = c;
    }
    for(int j = m; j >= 0; j--) {
        for(int k = 0; k <= pn; k++) {
            if(j >= v[k]) f[j] = max(f[j], f[j - v[k]] + w[k]);
        }
    }
    cout << f[m] << endl;
    return 0;
}