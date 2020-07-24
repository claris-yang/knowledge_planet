//
// Created by yangtao on 20-7-17.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 400010;
ll tree[N*2], m[N];
ll t, q, p;
ll lc(ll root) {
    return root << 1 ;
}
ll rc(ll root){
    return root << 1 | 1;
}

void build (ll root, ll l, ll r) {
    if(l == r) {
        tree[root] = 1;
        return;
    }
    ll mid = l + r >> 1;
    build(lc(root), l, mid);
    build(rc(root), mid + 1, r) ;
    tree[root] = tree[lc(root)] * tree[rc(root)] % p;
}

void change(ll root, ll l, ll r, ll pos, ll k) {
    if (l == r) {
        tree[root] = k;
        return;
    }
    ll mid = l + r >> 1;
    if( pos <= mid ) change(lc(root), l , mid, pos, k);
    else  change(rc(root), mid + 1, r, pos, k);
    tree[root] = tree[lc(root)] * tree[rc(root)] % p;
}

int main() {
    scanf("%lld" , &t);
    while(t--) {
        scanf("%lld%lld", &q, &p);
        build(1, 1, q);
        for(int i = 1; i <= q; i++) {
            int x;
            scanf("%d%lld", &x, &m[i]);
            if(x == 1) {
                change(1, 1, q, i, m[i]);
                printf("%lld\n", tree[1]);
            } else {
                change(1, 1, q, m[i], 1);
                printf("%lld\n", tree[1]);
            }
        }
    }
    return 0;
}
