//
// Created by yangtao on 19-12-6.
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
inline int ls(int n ) {return n << 1;}
inline int rs(int n ) {return n << 1 | 1;}
struct L {
    int x;
    int y1, y2;
    int state;
    bool operator<(const L & l) const {
        return x < l.x;
    }
}line[N];
int v[N];
struct Node {
    int l, r, cover;
    ll len;
}sgt[N<<3];
int n;
int pushup(int k ) {
    if(sgt[k].cover) sgt[k].len = sgt[k].r - sgt[k].l;
    else sgt[k].len = sgt[ls(k)].len + sgt[rs(k)].len;
}

void build(int l, int r, int k) {
    sgt[k].l = v[l], sgt[k].r = v[r];
    if( r - l <= 1) return;
    int m = (l+r)>>1;
    build(l, m, ls(k));
    build(m, r, rs(k));
    pushup(k);
}
void modify(int x, int y, int z, int k) {
    int l = sgt[k].l, r = sgt[k].r;
    if(x <= l && y >= r) {
        sgt[k].cover += z;
        pushup(k);
        return;
    }

    if( x < sgt[ls(k)].r) modify(x, y, z, ls(k));
    if( y > sgt[rs(k)].l) modify(x, y, z, rs(k));
    pushup(k);
}
int main() {
    cin >> n;
    for(int i  = 1; i <= n; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        v[i] = b, v[i+n] = d;
        line[i] = L{a, b, d, 1}, line[i+n] = L{c, b, d, -1};
    }
    sort( v + 1, v + (n << 1) + 1);
    sort( line + 1, line + (n << 1) + 1);

    build(1, n << 1, 1);
    unsigned long long ans = 0;
    for(int i = 1; i <= (n << 1); i++) {
        ans += sgt[1].len * (line[i].x - line[i-1].x);
        modify(line[i].y1, line[i].y2, line[i].state ,1);
    }

    cout << ans << endl;
    return 0;
}