//
// Created by yangtao on 20-8-19.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
int q[N], a[N], ans[N];
int n;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int t = 0;
    for(int i = 1; i <= n; i++) {
        while(t && a[q[t]] < a[i]) {
            ans[q[t]] = i;
            t--;
        }
        q[++t] = i;
    }

    for(int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
