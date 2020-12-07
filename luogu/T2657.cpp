//
// Created by yangtao on 20-11-20.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=20;
int digit[maxn];
ll dp[maxn][10];
ll dfs(int pos,int pre,bool limit,bool zero)
{
    if(pos==0)
        return 1;
    if(dp[pos][pre]!=-1&&!limit)
        return dp[pos][pre];
    ll ans=0;
    int up=limit?digit[pos]:9;
    for(int i=0;i<=up;i++)
        if( ( !zero&&abs(pre-i)>=2 ) ||zero)
            ans+=dfs(pos-1,i,limit&&i==up,zero&&i==0);
    if(!limit&&!zero)
        dp[pos][pre]=ans;
    return ans;
}
ll solve(ll x)
{
    int pos=1;
    while(x){
        digit[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,0,1,1);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    ll l,r;
    while(scanf("%lld%lld",&l,&r)==2){
        printf("%lld\n",solve(r)-solve(l-1));
    }
    return 0;
}
