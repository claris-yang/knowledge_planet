//
// Created by yangtao on 20-5-9.
//

#include <iostream>
using namespace std;
const int N = 1000005;
const int M = 10000;
int f[N];
int n;
int main() {
    cin >> n;
    f[0] = f[1] = 1;
    f[2] = 2;
    f[3] = 5;
    for(int i = 4; i <= n; i++) {
        f[i] = f[i-1] + f[i-2] + f[i-3] * 2 + f[i-4]*2;
    }
    cout << f[n];
    return 0;
}