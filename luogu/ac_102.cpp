//
// Created by yangtao on 20-6-28.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
int a[N];
int n, f;
int main() {
    cin >> n >> f;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i-1];
    }
    int l = f, r = n;
    while( l < r) {
        int mid = l + r >> 1;
        if(cal(mid)) {
            l
        } else {

        }
    }
}