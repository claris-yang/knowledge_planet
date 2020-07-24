//
// Created by yangtao on 20-2-20.
//

#include <iostream>
using namespace std;
const int N = 10005;
int n, m, w;
int f[N], ci[N], di[N];
int d[N];
int find(int c) {
    if(f[c] != c) f[c] = find(f[c]);
    return f[c];
}
int main() {

    cin >> n >> m >> w;
    for(int i = 1; i <= n; i++) {
        cin >> ci[i] >> di[i];
        // 初始化并查集
        f[i] = i;
    }

    for(int i = 0 ; i < m ; i++) {
        int x, y;
        cin >> x >> y ;
        if( find(x) != find(y) )  {
            f[find(y)] = find(x);
        }
    }

    for(int i = 1; i <= n; i++ ) {
        if(f[i] != i) {
            ci[find(i)] += ci[i];
            di[find(i)] += di[i];
            ci[i] = di[i] = 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = w; j >= ci[i]; j--) {
            d[j] = max(d[j], d[j - ci[i]] + di[i]);
        }
    }

    cout << d[w] << endl;

    return 0;
}