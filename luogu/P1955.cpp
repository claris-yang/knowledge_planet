#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;
const int N = 2e5 + 6;
int h[N], b[N];
int t, n, tot;
struct Opt {
    int x, y, f;
    bool operator<(const Opt &opt) const {
        return f > opt.f;
    }
};

Opt opt[N];

void init() {
    for(int i = 1; i <= tot; i++) h[i] = i;
}

int find( int x ) {
    if(h[x] != x) h[x] = find(h[x]);
    return h[x];
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) h[x] = y;
}
/* 这道题因为对操作数进行排序, 所以不用存储 a b 互斥, 就是不在一个集合里面的问题
 * 所以不用开2倍数组 */
int main() {
    cin >> t;
    while(t-- > 0) {
        cin >> n;
        bool flag = true;
        tot = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &opt[i].x, &opt[i].y, &opt[i].f);
            b[tot++] = opt[i].x; b[tot++] = opt[i].y;
        }
        sort(b, b + tot);
        sort(opt, opt + n);
        tot = unique(b, b + tot) - b;
        init();
        for(int i = 0; i < n; i++) {
            opt[i].x = lower_bound(b, b + tot, opt[i].x) - b + 1;
            opt[i].y = lower_bound(b, b + tot, opt[i].y) - b + 1;
        }

        for(int i = 0 ;i < n; i++) {
            if( opt[i].f == 0 ) {
                if( find(opt[i].x) == find(opt[i].y) ) {
                    flag = false;
                    break;
                }
            } else {
                union_set(opt[i].x, opt[i].y);
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}