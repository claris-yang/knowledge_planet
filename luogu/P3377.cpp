//
// Created by yangtao on 20-6-9.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
struct Node {
    int l, r, fa;
    int val, dis;
}ltt[N];

#define ls(x) ltt[x].l
#define rs(x) ltt[x].r

int merge(int x, int y) {
    if(!x || !y ) return x + y;
    if(ltt[x].val > ltt[y].val || (ltt[x].val == ltt[y].val && x > y))
        std::swap(x, y);
    rs(x) = merge(rs(x), y);
    ltt[rs(x)].fa = x;
    if(ltt[ls(x)].dis < ltt[rs(x)].dis)
        std::swap(ls(x), rs(x));
    ltt[x].dis = ltt[rs(x)].dis + 1;
    return x;
}

void pop(int x ) {
    ltt[x].val = -1;
    ltt[ls(x)].fa = ls(x);
    ltt[rs(x)].fa = rs(x);
    ltt[x].fa = merge(ls(x), rs(x));
}

int find(int x) {
    return ltt[x].fa == x ? x : ltt[x].fa = find(ltt[x].fa);
}
int n, m;
int main() {
    cin >> n >> m;
    ltt[0].dis = -1;
    for(int i = 1; i <=n; i++) {
        scanf("%d", &ltt[i].val);
        ltt[i].fa = i;
    }
    while(m--) {
        int opt, x, y;
        scanf("%d%d", &opt, &x);
        if(opt == 1) {
            scanf("%d", &y);
            if(ltt[x].val == -1 || ltt[y].val == -1 )
                continue;
            int fx = find(x), fy = find(y);
            if(fx == fy) continue;
            ltt[fx].fa = ltt[fy].fa = merge(fx, fy);
        } else {
            if(ltt[x].val == -1) printf("-1\n");
            else {
                int fx = find(x);
                printf("%d\n", ltt[fx].val);
                pop(fx);
            }
        }
    }
    return 0;
}