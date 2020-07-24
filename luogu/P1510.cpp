//
// Created by yangtao on 20-2-20.
//

#include <iostream>
using namespace std;
const int N = 10005;
int f[N], v, n, c;
int k,m;
int main() {
    cin >> v >> n >> c;

    for(int i = 0; i < n; i++) {
        cin >> k >> m;
        for(int j = c; j >= m; j--) {
            f[j] = max(f[j], f[j-m] + k);
        }

    }

    for(int i = 0; i <= c; i++) {
        if(f[i] >= v) {
            cout << c - i << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}