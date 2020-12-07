//
// Created by yangtao on 20-11-10.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 30005;
int f[N], dis[N], num[N];
int n;
void init() {
    for(int i = 1; i < N; i++) {
        f[i] = i, dis[i] = 0, num[i] = 1;
    }
}
int find(int x) {
    if(f[x] == x) return f[x];
    int fa = find(f[x]);
    dis[x] += dis[f[x]];

    return f[x] = fa;
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    f[x] = y;
    dis[x] += num[y];
    num[y] += num[x];
    num[x] = 0;

}
int main() {
    cin >> n;
    init() ;
    for(int i = 1; i <= n; i++) {
        char opt;
        int x, y;
        cin >> opt >> x >> y;
        if(opt == 'M') {
            merge(x, y);
        } else if( opt == 'C') {
            int fx = find(x);
            int fy = find(y);
            if(fx != fy) {
                cout << -1 << endl;
            } else {
                cout << abs(dis[x] - dis[y]) - 1 << endl;
            }
        }
    }
    return 0;
}