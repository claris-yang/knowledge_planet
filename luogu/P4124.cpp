//
// Created by yangtao on 20-11-25.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=30;
int digit[maxn];
ll dp[maxn][maxn][maxn][2][2][2][2];
ll l, r;
ll dfs(int pos,int one, int two, bool status, bool limit, bool has4, bool has8) {
    if( has4 && has8 ) return 0;
    if( pos <= 0 )
        return status;
    if( dp[pos][one][two][status][limit][has4][has8] != -1 )
        return dp[pos][one][two][status][limit][has4][has8];
    ll ans=0;
    int up=!limit?digit[pos]:9;
    for(int i=0;i<=up;i++){
        ans+=dfs(pos-1, i, one, status||(two == one && one == i), limit || (i < up), has4 || i == 4 , has8 || i == 8);
    }

    return dp[pos][one][two][status][limit][has4][has8]=ans;
}
ll solve(ll x) {
    if( x < 1e10 ) return 0;
    memset(dp, -1, sizeof(dp));
    int pos=0;
    while(x){
        digit[++pos]=x%10;
        x/=10;
    }
    ll res = 0 ;
    for(int i = 1; i <= digit[pos]; i++) {
        res += dfs( 10, i, 0, 0, i < digit[pos], i == 4, i == 8);
    }
    return res;
}
int main()
{
    cin >> l >> r;
    printf("%lld\n",solve(r)-solve(l-1));
    return 0;
}
