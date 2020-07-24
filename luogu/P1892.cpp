//
// Created by yangtao on 20-5-28.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1005;
int f[N * 2];
int n, m;
void init() {
    for(int i = 1; i <= n; i++) f[i] = i, f[i+n]= i + n;
}
int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
void union_set(int x, int y) {
    x = find(x) ;
    y = find(y) ;
    if(x != y) f[x] = f[y];
}
int res;
int cnt[N * 2];
int main() {
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++) {
        char c ;
        int x, y;
        cin >> c >> x >> y;
        if( c == 'E') {
            union_set(x, y + n);
            union_set(y, x + n);
        } else {
            union_set(x, y);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!cnt[find(i)]) res++, cnt[find(i)] = 1;
    }

    cout << res ;
    return 0;
}