//
// Created by yangtao on 20-5-28.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 13;
int f[N];
int hanoi() {
    memset(f, 0x3f, sizeof(f));
    f[1] = 1;
    for(int i = 2; i < N; i++) {
        for(int j = 1; j < i ; j++)
            f[i] = min(f[i], (1<<j)-1 + 2 * f[i - j]);
    }
    for(int i = 1; i < N; i++) {
        cout << f[i] << endl;
    }
    return 0;
}
int main() {
    hanoi();
    return 0;
}