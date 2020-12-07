//
// Created by yangtao on 20-11-25.
//
#include <bits/stdc++.h>
#define int unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int a,b;
int f[15][15][2][2];
int tot=0,num[15];
int dp(int x,int sum,int d,bool lim,bool zer) {
    /*
    x表示当前到了第几位，sum表示当前答案，d表示需要处理个数的数码，
    lim表示是否在上界，zer表示是否为前导0。
    */
    if(x==0) return sum;
    //递归到终点了，返回答案
    if(~f[x][sum][lim][zer]) return f[x][sum][lim][zer];
    //给f数组加入了lim和zer两个0/1量来保证返回的数据是符合当前条件的。
    int ans=0;
    rep(i,0,lim?num[x]:9) {
        //这里判断lim是为了处理在上界时只能for到b的那一位的情况。
        if(zer&&i==0) ans+=dp(x-1,sum,d,0,1); //前导的0不计入答案。
        else ans+=dp(x-1,sum+(i==d),d,lim&&(i==num[x]),0);
    }
    return f[x][sum][lim][zer]=ans; //赋值用于记忆化。
}
int sol(int d,int x) {
    memset(f,-1,sizeof(f));
    tot=0;
    while(x) num[++tot]=x%10,x/=10; //拆位。
    return dp(tot,0,d,1,1);
}
signed main(){
    scanf("%llu%llu",&a,&b);
    rep(i,0,9) printf("%llu ",sol(i,b)-sol(i,a-1));
    return 0;
}
