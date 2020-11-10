//
// Created by yangtao on 20-10-14.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int tree[N<<2], tag[N<<2], a[N];
int n, m, P, t, cnt;
ll lc(int i) {
    return i << 1;
}
ll rc(int i) {
    return i << 1 | 1;
}

void pushUp(int p) {
    tree[p] = max(tree[lc(p)], tree[rc(p)]);
}

void buildTree(int p , int l, int r) {
    if(l == r) {
        tree[p] = 0;
        return ;
    }
    int mid = l + r >> 1;
    buildTree(lc(p), l , mid);
    buildTree(rc(p), mid + 1, r);
    pushUp(p);
}

void moveTag(int p, int l, int r, int k) {
    tree[p] = max(tree[p], k);
    tag[p] = max(tag[p], k);
}

void pushDown(int p, int l, int r) {
    int mid = l + r >> 1;
    moveTag(lc(p), l, mid, tag[p]);
    moveTag(rc(p), mid + 1, r, tag[p]);
    tag[p] = 0;
}

int query(int p, int l, int r, int ql, int qr) {
    if( l >= ql && r <= qr) {
        return tree[p];
    }
    pushDown(p, l , r);
    int mid = l + r  >> 1;
    int res = 0;
    if( ql <= mid ) res = query(lc(p), l, mid, ql, qr);
    if( mid < qr ) res = max(res, query(rc(p), mid + 1, r, ql, qr));
    return res;
}

void update(int p, int l , int r, int ql , int qr, int k) {
    if( ql <= l && qr >= r) {
        tree[p] += k + t;
        tree[p] %= P;
        tag[p] += (k + t);
        tag[p] %= P;
        return ;
    }
    pushDown(p, l, r);
    int mid = l + r >> 1;
    if( ql <= mid ) {
        update(lc(p), l, mid, ql, qr, k);
    }
    if(mid < qr) {
        update(rc(p), mid + 1, r, ql, qr, k);
    }
    pushUp(p);
}

int main() {
    cin >> m >> P;
    buildTree(1, 1, 1e5);
    for(int i = 1; i <= m; i++) {
        char opt;
        int x;
        cin >> opt >> x;
        if( opt == 'A' ) {
            ++cnt;
            update(1, 1, 1e5, cnt ,cnt, x);
        } else {
            t = query(1, 1, 1e5 , cnt - x + 1, cnt);
            printf("%d\n", t);
        }
    }

    return 0;
}

