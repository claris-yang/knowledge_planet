//
// Created by yangtao on 20-7-13.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll a[N*2], tree[N*2], addtag[N*2], multag[N*2];
ll n, m, p;
ll lc(ll root) {
    return root << 1;
}
ll rc(ll root) {
    return root << 1 | 1;
}
void pushUp(ll root) {
    tree[root] = (tree[lc(root)] + tree[rc(root)] ) % p;
}

void moveTag(ll child, ll l, ll r, ll root) {
    multag[child] = (multag[child] * multag[root]) % p;
    addtag[child] = (addtag[child] * multag[root] + addtag[root]) % p;
}

void pushDown(ll root, ll l, ll r) {
    ll mid = l + r >> 1;
    tree[lc(root)] =  tree[lc(root)] * multag[root]   % p;
    tree[lc(root)] = ((mid - l + 1) * addtag[root] + tree[lc(root)] ) % p;
    tree[rc(root)] =  tree[rc(root)] * multag[root]   % p;
    tree[rc(root)] = ((r - mid + 1) * addtag[root] + tree[rc(root)] ) % p;

    moveTag(lc(root), l, mid, root);
    moveTag(rc(root), mid + 1, r, root);
    addtag[root] = 0;
    multag[root] = 1;
}

void update1(ll root, ll l, ll r, ll lq, ll rq, ll k) {
    if(lq <= l && rq >= r) {
        tree[root] = tree[root] * k % p;
        multag[root] = (multag[root] * k) % p;
        addtag[root] = (addtag[root] * k) % p;
        return ;
    }
    pushDown(root, l , r);
    ll mid = l + r >> 1;
    if(lq <= mid) update1(lc(root), l , mid , lq, rq, k);
    if(mid < rq)  update1(rc(root), mid + 1, r, lq, rq, k);
    pushUp(root);
}

void update2(ll root, ll l, ll r, ll lq, ll rq, ll k) {
    if(lq <= l && rq >= r) {
        tree[root] = (tree[root] + k * (r - l + 1) )  % p;
        addtag[root] = (addtag[root] + k) % p;
        return ;
    }
    pushDown(root, l , r);
    ll mid = l + r >> 1;
    if(lq <= mid) update2(lc(root), l , mid , lq, rq, k);
    if(mid < rq) update2(rc(root), mid + 1, r, lq, rq, k);
    pushUp(root);
}

void build(ll root, ll l , ll r) {
    if(l == r) {
        tree[l] = a[l] % p;
        return;
    }
    ll mid = l + r >> 1;
    build(lc(root), l, mid);
    build(rc(root), mid + 1, r);
    pushUp(root);
    multag[root] = 1;
}

ll query(ll root, ll l, ll r, ll lq, ll rq) {
    if(lq <= l && rq >= r) {
        return tree[root];
    }
    ll res = 0;
    pushDown(root, l , r);
    ll mid = l + r >> 1;
    if(lq <= mid) res =  query(lc(root), l , mid, lq, rq) % p;
    if(mid < rq)  res =  (res + query(rc(root), mid + 1, r, lq, rq) ) % p;
    return res;
}

int main() {
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++ ) scanf("%lld", &a[i]);
    build(1, 1, n);

    for(int i = 1; i <=m; i++) {
        ll t, x, y, k;
        scanf("%lld%lld%lld", &t, &x, &y);
        if(t == 1) {
            scanf("%lld", &k);
            update1(1, 1, n, x, y, k);
        } else if (t == 2) {
            scanf("%lld", &k);
            update2(1, 1, n, x, y, k);
        } else {
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }
    return 0;

}

