//
// Created by yangtao on 19-10-16.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define LL long long
#define maxn 100001

using namespace std;

struct node {
    int a, b, c;
}a[maxn];

LL f[maxn], ans;
int T, n, i, j;

bool cmp(node a, node b) {
    return (LL)a.c * (LL)b.b < (LL)b.c * (LL)a.b;
}

int main() {

    scanf("%d%d", &T, &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i].a);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i].b);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i].c);

    sort(a, a + n, cmp);

    memset(f, 255, sizeof f);
    f[0] = 0;

    for (i = 0; i < n; i++) {
        for (j = T; j >= 0; --j)
            if (f[j] != -1 && j + a[i].c <= T)
                f[j + a[i].c] = max(f[j + a[i].c], f[j] + (LL)a[i].a - (LL)(j + a[i].c) * (LL)a[i].b);
    }
    for (i = 0; i <= T; i++){
        ans = max(ans, f[i]);
    }

    cout << ans << endl;
}