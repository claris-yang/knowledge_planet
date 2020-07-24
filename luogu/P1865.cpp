//
// Created by yangtao on 19-11-14.
//

#include <iostream>
using namespace std;
const int N = 1e7 + 5;
int pri[N], ps[N];
int n, m;
int main() {
    cin >> n >> m;
    pri[1] = 1;
    for(int i = 2; i <= m; i++) {
        if( pri[i] == 0 ) {
            for(int j = i * 2; j <=m ; j += i) {
                pri[j] = 1;
            }
        }
    }

    for(int i = 1; i <=m ;i++) {
        ps[i] = ps[i - 1];
        if (pri[i] == 0) {
            ps[i] += 1;
        }
    }

    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if(l < 1 || r > m ) {
            cout << "Crossing the line" << endl;
        } else {
            cout << ps[r] - ps[l-1] << endl;
        }
    }
    return 0;
}

