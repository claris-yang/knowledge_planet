//
// Created by yangtao on 20-6-28.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int N = 10005;
int a[N], c[N];
int n, p, h, m;
map<pair<int, int>, int> mm;
int main() {
    cin >> n >> p >> h >> m;
    for(int i = 0 ;i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x > y) swap(x, y);
        if(mm.find({x, y}) != mm.end()) continue;
        mm[{x,y}] = 1;
        a[x+1] -= 1;
        a[y] += 1;
    }

    for(int i = 1; i <=n; i++)
        c[i] = c[i-1] + a[i];

    for(int i = 1; i <=n; i++)
        cout << c[i] + h << endl;

    return 0;
}

