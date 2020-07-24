//
// Created by yangtao on 19-10-25.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN
using namespace std;
struct Node {
    int x, y;
    double c;
    bool operator<(const Node &n) const {
        return c < n.c;
    }
};
int s, p;
int fa[10005];
int visit[10005];
int x[10005], y[10005];
Node a[100000005];
int find(int x) {
    if(fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];

}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y) ;
    if(fx != fy) fa[fx] = fy;
}
int main() {
    cin >> s >> p;
    for(int i = 1; i <= p ; i++) {
        cin >> x[i] >> y[i];
    }

    int idx = 0;
    for(int i = 1; i <= p; i++) {
        for(int j = 1; j < i ; j++) {
            if(i != j) {
                Node t;
                t.x = i;
                t.y = j;
                t.c = sqrt( (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) );
                a[++idx] = t;
            }
        }
    }

    sort(a+1, a+idx+1);
    for(int i = 1; i <= p; i++ ) {
        fa[i] = i;
    }

    int k = 0;
    int i;
    for(i = 1 ; i <= idx; i++) {
        if(find(fa[a[i].x]) != find(fa[a[i].y])) {
            merge(a[i].x, a[i].y);
            k++;
            if(k == p - s) break;

        }
    }
    printf("%.2lf", a[i].c);
    return 0;
}