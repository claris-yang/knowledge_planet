//
// Created by yangtao on 20-11-24.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 30;
ll dp[N][N], digit[100];
ll n, m;
ll dfs(int pos, bool limit, bool zero, ll d, ll cnt) {
    if( pos == 0 ) {
        return cnt;
    }
    if( dp[pos][cnt] != -1 && !limit && !zero ) return dp[pos][cnt];

    int up = limit ? digit[pos] : 9;
    ll ans = 0;
    for(int i = 0 ; i <= up; i++ ) {
        ans += dfs(pos - 1, limit && (i == up), zero && (i == 0), d, cnt + ((!zero || i) && (i == d)) ) ;
    }
    if(!limit && !zero) dp[pos][cnt] = ans;
    return ans;
}
ll solve(ll x, ll d) {
    int pos = 0;
    while(x) {
        digit[++pos] = x % 10;
        x /= 10;
    }
    memset(dp, -1, sizeof(dp));
    return dfs(pos, 1, 1, d, 0);
}
int main() {
    cin >> n >> m;
    for(int i = 0 ; i <= 9; i++) {
        printf("%lld ", solve(m, i) - solve(n - 1, i));
    }
    return 0;
}