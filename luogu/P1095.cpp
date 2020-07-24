//
// Created by yangtao on 20-4-13.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 300005;
int t, m, s;
int f[N];
int main() {
    cin >> m >> s >> t;
    for(int i = 1; i<= t; i++) {
        if( m >= 10) {
            f[i] = f[i-1] + 60;
            m -= 10;
        } else {
            f[i] = f[i-1];
            m+=4;
        }
    }

    for(int i = 1; i <= t; i++) {
        f[i] = max(f[i], f[i-1] + 17);
        if(f[i] >= s) {
            cout << "Yes" << endl << i;
            return 0;
        }
    }

    cout << "No" << endl << f[t];
    return 0;
}