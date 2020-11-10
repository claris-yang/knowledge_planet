//
// Created by yangtao on 20-10-9.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll tree[N<<2], tag[N<<2], tagm[N<<2], a[N];
inline int lc(int p) {
    return p << 1;
}
inline int rc(int p) {
    return p << 1 | 1;
}
int n,m, P;
void movetag(int p, int l , int r, ll w, ll w2) {
    tagm[p] *= w % P;
    tree[p] *= w % P;
    tag[p] *= w;
    tag[p] += w2;
    tree[p] += (r-l+1)*w2;
    tree[p] %= P;
    tag[p] %= P;
    tagm[p] %= P;
}
void pushdown(int p, int l , int r) {
    int mid = (l + r) >> 1;
    movetag(lc(p), l, mid, tagm[p], tag[p]);
    movetag(rc(p), mid + 1, r,  tagm[p], tag[p]);
    tag[p] = 0;
    tagm[p] = 1;
}
void pushup(int p , int l , int r) {
    tree[p] = (tree[lc(p)] + tree[rc(p)]) % P;
}
void update(int p, int l , int r, int ql, int qr, ll w, ll w2) {
    if(l >= ql && r <= qr) {
        movetag(p, l, r, w, w2);
        return;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if(ql <= mid) {
        update(lc(p), l, mid, ql, qr, w, w2);
    }
    if( qr > mid ) {
        update(rc(p), mid + 1, r, ql, qr, w, w2);
    }
    pushup(p, l, r);
}
void buildTree(int p, int l , int r) {
    tag[p] = 0;
    tagm[p] = 1;
    if(l == r) {
        tree[p] = a[l];
        return ;
    }
    int mid = l + r >> 1;
    buildTree(lc(p), l , mid);
    buildTree(rc(p), mid + 1, r);
    pushup(p, l, r);
}
ll query(int p, int l , int r, int ql, int qr) {
    if( l >= ql && r <= qr) {
        return tree[p];
    }
    pushdown(p, l , r);
    int mid = l + r >> 1;
    ll res = 0;
    if( ql <= mid ) {
        res += query(lc(p), l , mid, ql, qr);
    }
    if( qr > mid) {
        res += query(rc(p), mid  + 1, r, ql, qr);
    }
    res %= P;
    return res;
}
int main() {

    scanf("%d%d%d", &n, &m, &P);
    for(int i = 1; i <=n; i++) {
        scanf("%lld", &a[i]);
    }
    buildTree(1, 1, n);
    for(int i = 1; i <= m; i++) {
        int opt, l , r, k;
        scanf("%d%d%d", &opt, &l , &r);
        if(opt == 1) {
            scanf("%d", &k);
            update(1, 1, n, l , r , k, 0);
        } else if (opt == 2) {
            scanf("%d", &k);
            update(1, 1, n, l, r, 1, k);

        } else if (opt == 3) {
            printf("%lld\n", query(1, 1, n, l , r));
        }
    }
    return 0;
}
