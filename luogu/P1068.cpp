//
// Created by yangtao on 20-11-5.
//

#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int cnt;
struct Stu{
    int num;
    int sco;
    bool operator<(const Stu & stu)const{
        if(sco==stu.sco){
            return num > stu.num;
        }
        return stu.sco<sco;
    }
};
Stu a[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].sco;
    }
    sort(a+1,a+n+1);
    m=int(m*1.5);
    for(int i=1;a[i].sco>=a[m].sco;i++){
        cnt++;
    }
    cout<<a[m].sco<<" "<<cnt<<endl;
    for(int i=1;i<=cnt;i++){
        cout<<a[i].num<<" "<<a[i].sco<<endl;
    }
    return 0;
}