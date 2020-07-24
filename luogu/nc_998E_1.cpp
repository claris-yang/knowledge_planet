//
// Created by yangtao on 20-5-28.
//

#include<iostream>
#include<cstring>
using namespace std;
int sav[13];
int main()
{
    int i,j,k;
    memset(sav,0,sizeof(sav));
    sav[0]=0;
    sav[1]=1;
    sav[2]=3;
    sav[3]=5;
    for(i=4;i<=12;i++)
    {
        int cnt=1000000,num=0;
        for(k=1;k<=i;k++)
        {
            int t=2*sav[i-k]+(1<<k)-1;
            if(t<cnt)cnt=t;
        }
        sav[i]=cnt;
    }
    for(i=1;i<=12;i++)
        cout<<sav[i]<<endl;
    return 0;
}