//
// Created by yangtao on 20-10-27.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5005;
struct Edge{
    int u, v, w;
};
vector<Edge> a[N];
int main( ) {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int x, y, ww;
        scanf("%d%d%d", &x, &y, &ww);
        a[x].push_back({x,y,ww});
        a[y].push_back({y,x,ww});
    }

    for(int i = 1; i <= n; i++) {
        cout << a[i].size() << " ";
    }

    return 0;
}