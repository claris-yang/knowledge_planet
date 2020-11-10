//
// Created by yangtao on 20-10-13.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 200005;
int tree[N<<2], a[N], tag[N<<2];
int n,m;
int lc(int p) {
    return p << 1;
}
int rc(int p) {
    return (p << 1) | 1;
}

void pushup(int p) {
    tree[p] = max(tree[lc(p)], tree[rc(p)]);
}

void buildTree(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        return ;
    }
    int mid = l + r >> 1;
    buildTree(lc(p), l, mid);
    buildTree(rc(p), mid + 1, r);
    pushup(p);
}

void movetag(int p, int w) {
    tree[p] = max(tree[p], tag[p]);
    tag[lc(p)] = max(tag[lc(p)], w);
    tag[rc(p)] = max(tag[rc(p)], w);
    tag[p] = 0;
}

void pushdown(int p) {
    movetag(lc(p), tag[p]);
    movetag(rc(p), tag[p]);
    tag[p] = 0;
}

int query(int p, int l, int r, int ql, int qr) {
    if(l >= ql && r <= qr) {
        return tree[p];
    }
    pushdown(p);
    int mid = l + r >> 1;
    int ans = 0;
    if(ql <= mid) {
        ans = max(ans, query(lc(p), l, mid, ql, qr));
    }
    if(qr > mid) {
        ans = max(ans, query(rc(p), mid + 1, r, ql, qr));
    }

    return ans;
}

void update(int p, int l, int r, int ql, int qr, int w) {
    if( ql <= l && r <= qr ) {
        movetag(p, w);
        return;
    }

    int mid = l + r >> 1;
    pushdown(p);
    if( ql <= mid ) {
        update(lc(p), l, mid, ql, qr, w);
    }
    if( qr > mid) {
        update(rc(p), mid + 1, r, ql, qr, w);
    }
    pushup(p);
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    buildTree(1, 1, n);

    for(int i = 1; i <= m; i++) {
        char opt;
        int x, y;
        cin >> opt;
        scanf("%d%d", &x, &y);
        if(opt == 'U') {
            if(a[x] < y) {
                update(1, 1, n, x, x ,y);
            }
        } else {
            printf("%d\n", query(1, 1, n, x, y));
        }
    }
    return 0;
}