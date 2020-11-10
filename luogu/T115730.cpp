//
// Created by yangtao on 20-10-14.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5005;
int b1[N], b2[N];
int n, m;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        b1[x]++, b2[y]++;
    }
    for(int i = 1; i <= n; i++) {
        printf("%d ", b1[i]);
    }
    cout << endl;
    for(int i = 1; i <= n; i++) {
        printf("%d ", b2[i]);
    }
    return 0;
}
