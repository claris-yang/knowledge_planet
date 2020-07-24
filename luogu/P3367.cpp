//
// Created by yangtao on 19-8-12.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#define VER_NUM 200005
using namespace std;
int parent[VER_NUM];
int n, m;
int idx;
bool ans[VER_NUM];
int find(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
    parent[find(x)] = find(y);
}
bool is_same_set(int x, int y) {
    return find(x) == find(y);
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <=n; i++) {
        parent[i] = i;
    }
    for(int i = 0 ;i < m; i++) {
        int zi, xi, yi;
        scanf("%d%d%d", &zi, &xi, &yi);

        if( zi == 1 ) {
            merge(xi, yi) ;
        } else {
            ans[idx++] = is_same_set(xi, yi);
        }
    }
    for(int i = 0; i < idx; i++) {
        if(ans[i]) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}