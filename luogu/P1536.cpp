//
// Created by yangtao on 20-5-19.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1005;
int f[N];
int n, m;
void init(){
    for(int i = 1; i <= n; i++) f[i] = i;
}
int find(int x) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}
void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) f[x] = f[y];
}
int main() {
    while( cin >> n >> m) {

        init();

        for(int i = 0 ;i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            union_set(x, y);
        }

        int cnt = 0;
        for(int i = 1; i <=n; i++) {
            if(f[i] == i ) cnt++;
        }

        printf("%d\n", cnt-1);
    }
}