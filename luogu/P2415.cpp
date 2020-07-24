//
// Created by yangtao on 20-5-29.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 35;
int a[N], v[N], b[N];
int n, res;
void dfs(int x, int y) {
    if(y > n) {
        int s = 0;
        for(int i = 1; i <=n; i++) {
            s += b[i];
        }
        cout << s << endl;
        res += s;
        return ;
    }
    for(int i = x; i <=n; i++) {
        if(v[i]) continue;
        v[i] = 1;
        b[y] = i;
        dfs(i + 1, y + 1);
        b[y] = 0;
        v[i] = 0;
    }
}
int main() {
    int t;
    while( cin >> a[++n] ) ;
    cout << n << endl;
    dfs(1, 1);
    cout << res << endl;
    return 0;
}
