//
// Created by yangtao on 20-4-3.
//

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define Ll long long
using namespace std;
Ll CC[1001][1001];
Ll C(Ll n,Ll m){
    if(CC[n][m])return CC[n][m];
    if(m==1)return n;
    if(m==0||m==n)return 1;
    if(m>n)return 0;
    CC[n][m]=C(n-1,m)+C(n-1,m-1);
    return CC[n][m];
}
int a[10],v[100];
Ll ans;
int n;
char c;
Ll cfb(){
    Ll ans=1;
    int m=n;
    for(int i=0;i<=9;i++)if(a[i])ans*=C(m,a[i]),m-=a[i];
    return ans;
}
int main()
{
    while(cin>>c)if(isdigit(c))v[++n]=c-48,a[v[n]]++;
    int nn=n;
    for(int i=1;i<=nn;i++){
        n--;
        for(int j=0;j<v[i];j++)
            if(a[j]){a[j]--;ans+=cfb();a[j]++;}
        a[v[i]]--;
    }
    printf("%lld",ans);
}