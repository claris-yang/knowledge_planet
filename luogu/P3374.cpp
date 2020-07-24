
//
// Created by yangtao on 20-4-7.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 5e5+5;
int d[N];
int n,m;
int lowbit(int x) {
    return x & (-x);
}
void add(int i, int x ) {
    while(i <=n ) {
        d[i] += x;
        i += lowbit(i);
    }
}
void sub(int i, int x) {
    while(i <= n ) {
        d[i]-=x;
        i += lowbit(i);
    }
}

int sum(int x) {
    int res = 0;
    while(x > 0) {
        res += d[x];
        x -= lowbit(x);
    }
    return res;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        add(i, t);
    }
    for(int i = 1; i <= m; i++){
        int c, x, y;
        scanf("%d%d%d", &c, &x, &y);
        if(c == 1) {
            add(x, y);
        } else if (c == 2) {
            printf("%d\n", sum(y) - sum(x-1));
        }
    }
    return 0;
}
