//
// Created by yangtao on 20-7-28.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int primer[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
ll  ans = -1, n, k ;
void dfs(ll x, ll y, ll t, ll cnt) {
    if( x > 11) return;
    if( t > n ) return;
    if( cnt > k ) {
        ans = t;
        k = cnt;
    } else if(cnt == k) {
        ans = min(ans, t);
    }

    for(int i = 1; i <= y; i++) {
        t *= primer[x];
        if( t > n) return;

        dfs( x + 1, y , t , cnt * (i + 1));
    }
}
int main() {
    cin >> n;
    dfs( 0, 31, 1, 1);
    cout << ans ;
    return 0;
}
