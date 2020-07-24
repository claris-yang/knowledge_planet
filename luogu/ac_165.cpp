//
// Created by yangtao on 20-5-25.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 20;
int cnt, n, w;
int cab[N], c[N];
int res;
void dfs(int now , int cnt ) {
    if (cnt > res) return ;
    if ( now > n ) {
       res = min(cnt, res);
       return ;
    }
    for(int i = 1; i <= cnt; i++) {
        if(cab[i] + c[now] <= w) {
            cab[i] += c[now];
            dfs(now+1, cnt);
            cab[i] -= c[now];
        }
    }
    cab[now+1, cnt+1] = c[now];
    dfs(now + 1, cnt + 1);
    cab[cnt + 1];
}
int main() {
    cin >> n >> w;
    for(int i = 1; i <= n; i++) cin >> c[i];
    sort(c + 1, c + n + 1);
    reverse(c + 1, c + n + 1);
    res = n;
    dfs(1, 0);
    cout << res << endl;
    return 0;
}
