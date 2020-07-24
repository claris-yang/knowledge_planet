//
// Created by yangtao on 20-5-14.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5005;
int f[N];

int n,m, p;
void init() {
    for(int i = 1; i <= n; i++) f[i] = i;
}
int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if( x != y ) f[x] = f[y];
}
int main() {
    cin >> n >> m >> p;
    init();
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        union_set(x, y);
    }
    for(int i = 0 ; i < p ; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(find(x) != find(y)) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}
