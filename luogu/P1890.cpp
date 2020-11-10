//
// Created by yangtao on 20-10-14.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int a[N], tree[N<<2];
int n, m;
int lc(int p ) {
    return p << 1;
}
int rc(int p ) {
    return p << 1 | 1;
}
void pushup(int p, int l, int r) {
    tree[p] = __gcd(tree[lc(p)], tree[rc(p)]);
}
void buildTree(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        return ;
    }
    int mid = l + r >> 1;
    buildTree(lc(p), l, mid);
    buildTree(rc(p), mid+1, r);
    pushup(p, l, r);

}

int query(int p, int l, int r, int ql , int qr) {
    if(l >= ql && r <= qr) {
        return tree[p];
    }
    int mid = l + r >> 1;
    int res = 0;
    if( ql <= mid ) {
        res = query(lc(p), l, mid , ql, qr);
    }
    if ( qr > mid ) {
        res = __gcd(res, query(rc(p), mid+1, r, ql, qr));
    }
    return res;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    buildTree(1, 1, n);

    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", query(1, 1, n, x, y));
    }
    return 0;
}
