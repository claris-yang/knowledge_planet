//
// Created by yangtao on 20-4-8.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using  namespace std;
const int N = 50005;
int a[N];
int l, r;
int len, n, m;

bool calc(int x) {
    int p = 1, rest = x;
    for(int i = 1; i<= n; i++) {
        if(rest >= a[i]) rest -= a[i];else p++, rest = x-a[i];
    }
    cout << x << " " << p << endl;
    return n - p <= m;
}

int main() {
    cin >> len >> n >> m;
    for(int i = 1; i <= n ; i++) {
        scanf("%d", &a[i]);
    }

    l = 0, r = len;
    int ans = 0;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if( calc(mid) ) l = mid; else r = mid - 1;
    }

    cout << l << endl;

    return 0;
}
