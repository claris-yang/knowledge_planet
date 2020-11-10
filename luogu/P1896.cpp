//
// Created by yangtao on 20-9-28.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef  long long ll;
const int N = 2005;
int sit[N], gs[N];
int cnt, n, yong;
ll f[10][N][100] ;
void dfs(int h, int sum, int node) {
    if (node >= n) {
        sit[++cnt] = h;
        gs[cnt] = sum;
        return ;
    }
    dfs(h, sum, node+1);
    dfs(h + (1 << node), sum +  1, node + 2);
}
int main() {
    cin >> n >> yong;
    dfs(0, 0, 0);
    for(int i =1 ; i <= cnt; i++) {
        f[1][i][gs[i]] = 1;
    }

    for(int  i = 2; i <= n; i++) {
        for(int j = 1; j <=cnt; j++) {
            for(int k = 1; k <= cnt; k++) {
                if(sit[j] & sit[k]) continue;
                if((sit[j] << 1) & sit[k]) continue;
                if(sit[j] & (sit[k] << 1)) continue;
                for(int s = yong; s >= gs[j]; s--) {
                    f[i][j][s] += f[i-1][k][s-gs[j]];
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= cnt; i++) ans += f[n][i][yong];
    cout << ans;
    return 0;
}

