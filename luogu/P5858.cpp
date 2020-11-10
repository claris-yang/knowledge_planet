//
// Created by yangtao on 20-9-23.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 5505;
ll n,m, s, a[N], f[N][N], q[N], pos[N];
int main() {
    cin >> n >> m >> s;
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    for(ll i = 0; i <= n; i++) {
        for(ll j = 0; j <= m; j++) {
            f[i][j] = -1008600110086001;
        }
    }
    f[0][0] = 0;
    for(ll i = 1; i <= n; i++) {
        int l=1,r=1;
        q[l]=f[i-1][m];
        pos[l]=m;
        for(long long j=m;j;--j)
        {
            while(pos[l]>j+s-1 && l<=r)	{
                ++l;
            }
            while(q[r]<f[i-1][j-1] && l<=r)	{
                --r;
            }
            pos[++r]=j-1;
            q[r]=f[i-1][j-1];
            f[i][j]=q[l]+j*a[i];
        }
    }
    long long ans=-1008600110086001;
    for(long long i=0;i<=m;++i)
        ans=max(ans,f[n][i]);
    cout << ans;
    return 0;
}
