//
// Created by yangtao on 20-10-13.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 5e4 +5;
int n, m;
ll a[N], tag[N << 2];
struct Node {
    int mmax, mmin;
} tree[N << 2];

int lc(int p) {
    return p << 1;
}

int rc(int p ) {
    return p << 1 | 1;
}

void pushup(int p) {
    tree[p].mmax = max(tree[lc(p)].mmax, tree[rc(p)].mmax);
    tree[p].mmin = min(tree[lc(p)].mmin, tree[rc(p)].mmin);
}

void buildTree(int p, int l, int r) {
    tag[p] = 0;
    if(l == r) {
        tree[p].mmax = tree[p].mmin = tree[p].val = a[l];
        return ;
    }
    int mid = l + r >> 1;
    buildTree(lc(p), l, mid);
    buildTree(rc(p), mid + 1, r);
    pushup(p);
}

int query(int p, int l, int r, int ql, int qr, int k) {
    if(l >= ql && r <= qr) {
        if ( k == 0 ) return tree[p].mmax; else return tree[p].mmin;
    }
    int mid = l + r >> 1;
    int res1 = 0 , res2 = 0 ;
    if(k) {
        res1 = res2 = 0x3f3f3f3f;
    }

    if( ql <= mid) {
        res1 = query(lc(p), l, mid, ql, qr, k);
    }

    if( qr > mid ) {
        res2 = query(rc(p), mid + 1, r, ql, qr, k);
    }

    if( !k ) {
        return max(res1, res2);
    } else {
        return min(res1, res2);
    }

}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    buildTree(1, 1, n);
    for(int i = 1; i <= m ;i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", query(1, 1, n, x, y, 0) - query(1, 1, n, x, y, 1));
    }
    return 0;
}