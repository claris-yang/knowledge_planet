//
// Created by yangtao on 20-5-9.
//

#include <iostream>
using namespace std;
const int N = 20;
int n;
int f[N];
int main() {
    cin >> n;
    f[0]  = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            f[i] += f[j-1] * f[i-j];
        }
    }
    cout << f[n];
    return 0;
}
