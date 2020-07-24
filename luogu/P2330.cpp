//
// Created by yangtao on 19-10-24.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int m, n, u, v, c, maxn, k;
int fa[301];
int find(int x) {
    if(fa[x]!=x)
        fa[x]=find(fa[x]);
    return fa[x];
}
void unionn(int x,int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) fa[fx]=fy;
}
struct Node {
    int x, y, v;
    bool operator < (const Node &b) const {
        return v<b.v;
    }
}a[51000];
int main() {
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> c;
        a[i]=(Node){u, v, c};
    }
    for (int i=1; i<=n; i++) fa[i]=i;
    sort(a+1,a+m+1);
    for (int i=1; i<=m; i++) {
        if (find(fa[a[i].x]) != find(fa[a[i].y])) {
            unionn(a[i].x, a[i].y);
            maxn = a[i].v;
            k++;
        }
        if (k == n-1) break;
    }
    cout<< n-1 << " " <<maxn;
    return 0;
}