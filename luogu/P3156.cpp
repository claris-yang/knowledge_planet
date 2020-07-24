//
// Created by yangtao on 20-4-21.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 2e6 + 5;
int a[N];
int n, m;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        printf("%d \n", a[t]);
    }
    return 0;
}