//
// Created by yangtao on 20-7-13.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
int n, m;
ll a[N], tree[N <<  2] , tag[N << 2];

inline ll lc(int i ) {
    return i << 1;
}

inline ll rc(int i ) {
    return i << 1 | 1;
}

void pushUp(int i) {
    tree[i] = tree[lc(i)] + tree[rc(i)];
}

void moveTag(int i, int l, int r, int k ) {
    tree[i] += k * (r - l + 1);
    tag[i] += k;
}

void pushDown(int i, int l, int r) {
    int mid = l + r >> 1;
    moveTag(lc(i), l, mid, tag[i]);
    moveTag(rc(i), mid + 1, r, tag[i]);
    tag[i] = 0;
}

void update(int i, int l, int r, int lq, int rq, int k) {
    if( lq <= l && rq >= r) {
        tree[i] += k * (r - l + 1);
        tag[i] += k;
        return ;
    }
    pushDown(i, l, r);
    int mid = (l + r) >> 1;
    if( lq <= mid ) {
        update(lc(i), l, mid, lq, rq, k);
    }
    if( mid < rq) {
        update(rc(i), mid + 1, r, lq, rq, k);
    }
    pushUp(i);
}

ll query(int i, int l , int r, int lq, int rq) {
    if(lq <= l && rq >= r) {
        return tree[i];
    }
    pushDown(i, l, r);
    int mid = l + r >> 1;
    ll res = 0;
    if(lq <= mid) {
        res += query(lc(i), l, mid, lq, rq);
    }
    if(mid < rq) {
        res += query(rc(i), mid+1, r, lq, rq);
    }
    return res;
}

void build (int i, int l, int r) {
    if(l == r) {
        tree[i] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(lc(i), l, mid);
    build(rc(i), mid + 1, r);
    pushUp(i);
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    for(int i = 0; i < m; i++) {
        ll p, x, y, t;
        if(p == 1) {
            scanf("%lld%lld%lld", &x, &y, &t);
            update(1, 1, n, x, y, k);
        } else {
            scanf("%lld%lld", &x, &y);
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }
    return 0;
}
