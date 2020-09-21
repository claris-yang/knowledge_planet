//
// Created by yangtao on 20-8-18.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 155;
int f[N][N], idx;
int h[N], e[N], ne[N], s[N];
int n, p;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u]=idx++;
}

int dfs(int u) {
    if(s[u] == 0) {
        f[u][1] = 0;
        return 1;
    }
    int sum = 1;
    for(int i = h[u]; ~i ; i = ne[i])  {
        int v = e[i];
        int t = dfs(v);
        sum+=t;
        for(int j = sum; j >= 0; j--) {
            for(int k =1; k < j; k++) {
                f[u][j] = min(f[u][j], f[u][j-k] + f[v][k] - 1);
            }
        }
    }

    return sum ;
}
int main() {
    cin >> n >> p;
    memset(h, -1, sizeof(h));
    for(int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        s[x]++;
    }
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++) {
        f[i][1] = s[i];
    }
    dfs(1);
    int ans = f[1][p];
    for(int i = 1; i <= n; i++) {
        ans = min(ans, f[i][p] + 1);
    }
    cout << ans << endl;
    return 0;
}