//
// Created by yangtao on 20-7-2.
//

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100010;
struct u {
    int v,len;
};
int n, m, v[maxn], d[maxn*3+1];
vector<u> G[maxn*3+1];

void addedge(int x,int y) {
    G[x].push_back((u){y,0});
    G[x+n].push_back((u){y+n,0});
    G[x+2*n].push_back((u){y+2*n,0});
    G[x].push_back((u){y+n,-v[x]});
    G[x+n].push_back((u){y+2*n,v[x]});
    return;
}

queue<int> Q;
bool inq[maxn*3+1];

void spfa() {
    for(int i = 1;i <= n;i++)    d[i] = -0x3f3f3f3f;
    d[1] = 0;
    inq[1] = true;
    Q.push(1);
    while(!Q.empty()) {
        int tp = Q.front(); Q.pop();
        inq[tp] = false;
        int len = G[tp].size();
        for(int i = 0;i < len;i++) {
            u x = G[tp][i];
            if(d[x.v] < d[tp] + x.len) {
                d[x.v] = d[tp] + x.len;
                if(inq[x.v] == false) {
                    Q.push(x.v);
                    inq[x.v] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> v[i];
    for(int i = 1,x,y,z;i <= m;i++) {
        cin >> x >> y >> z;
        addedge(x,y);
        if(z == 2) addedge(y,x);
    }
    G[n].push_back((u){3*n+1,0});
    G[n*3].push_back((u){3*n+1,0});
    n = 3*n + 1;

    spfa();
    cout << d[n] << endl;
    return 0;
}