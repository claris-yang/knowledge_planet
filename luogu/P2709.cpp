#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 50005;
int n,m,k;

int b[N], a[N], cnt[N];
struct Node {
    int l, r;
    int k;
    bool operator<(const Node & node) {
        return b[l] == b[node.l] ? r < node.r : b[l] < b[node.l];
    }
} q[N];
long long ans[N];
long long  res;

void add(int p) {
    cnt[a[p]]++;
    res = res + ( cnt[a[p]] * cnt[a[p]]) - (cnt[a[p]]-1) * (cnt[a[p]] - 1);
}

void sub(int p) {
    cnt[a[p]]--;
    res = res - (cnt[a[p]] + 1) * (cnt[a[p]] + 1) + ( cnt[a[p]] * cnt[a[p]]);
}

int main() {

    cin >> n >> m >> k;
    int siz = sqrt(n);
    for(int i = 1 ; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = i / siz;
    }


    for(int i = 0 ;i < m; i++) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].k = i ;
    }

    sort(q, q + m);

    int l = 1, r = 0;
    for(int i = 0 ; i < m ; i++) {

        while( q[i].l < l) add(--l);
        while( q[i].r > r) add(++r);
        while( q[i].l > l) sub(l++);
        while( q[i].r < r) sub(r--);

        ans[q[i].k] = res;
    }

    for(int i = 0 ;i < m; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
