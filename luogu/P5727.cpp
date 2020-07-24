//
// Created by yangtao on 20-4-29.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int N = 10005;
int n, cnt;
int d[N];
void dfs() {
    d[cnt++] = n;
    if (n == 1) return;
    if (n % 2 == 0) n /= 2;
    else n = n * 3 + 1;
    dfs();
}
int main() {
    cin >> n;
    dfs();
    for(int i = cnt - 1; i >= 0; i--) printf("%d ", d[i]);
    return 0;
}
