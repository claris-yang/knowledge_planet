//
// Created by yangtao on 20-6-19.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 15;
int fact(int a) {
    int res = 1;
    for(int i = 1; i <= a; i ++ ) {
        res *= i;
    }
    return res;
}
int comb(int a, int b) {
    return fact(a) / (fact(b) * fact(a-b));
}

int n , s, a[N], yh[N], v[N], cur;
void dfs(int r) {
    if(r == n + 1) {
        if(cur == s) {
            for(int i = 1; i <= n; i++) {
                printf("%d ", a[i]);
            }
            exit(0);
        }
    }
    for(int i = 1; i <= n; i++) {
        if( cur + yh[r] * i > s || v[i] ) continue;
        a[r] = i;
        v[i] = 1;
        cur += yh[r] * i;
        dfs(r+1);
        cur -= yh[r] * i;
        v[i] = 0;
    }
}
int main() {
    cin >> n >> s ;
    for(int i = 1; i <= n; i++) {
        yh[i] = comb(n-1, i-1);
    }
    dfs(1);
    return 0;
}