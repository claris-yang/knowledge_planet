//
// Created by yangtao on 20-6-18.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5;
int st[N][20], lg[N];
int n, m;
int query(int l, int r) {
    int k = lg[(r - l + 1) >> 1] ;
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &st[i][0]);
    }
    for(int i = 1;i <= n; i++) {
        lg[i] = lg[i-1] + ( (1 << lg[i-1]) == i);
    }
    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j-1] , st[i + (1 << (j-1))][j-1]);
        }
    }
    for(int i = 0 ;i < m; i++)  {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}