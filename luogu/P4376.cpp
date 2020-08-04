//
// Created by yangtao on 20-7-29.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e6 + 5;
int n,m;
vector<int> vec[N], top[N];
priority_queue<int> q;
queue<int> p;
int result[N], rudu[N];
void read(int &in){
    char c=getchar();in=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')in=in*10+c-'0',c=getchar();
}
void build(int x) {
    memset(rudu, 0, sizeof(rudu));
    memset(top, 0, sizeof(top));
    for(int i = 1; i <= x; i++ ) {
        for(int j = 1; j < vec[i].size(); j++) {
            top[vec[i][j-1]].push_back(vec[i][j]);
            rudu[vec[i][j]]++;
        }
    }
}

int topo() {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!rudu[i]) {
            p.push(-i);
            cnt++;
        }
    }
    int no = 0;
    while(!p.empty()) {
        int v = -p.front();
        result[++no] = v;
        p.pop();
        for(int i = 0; i < top[v].size(); i++) {
            rudu[top[v][i]]--;
            if(!rudu[top[v][i]]) {
                p.push(-top[v][i]);
                cnt++;
            }
        }
    }

    return cnt == n;
}
void find(int x) {
    build(x);
    for(int i = 1; i <= n; i++) {
        if(!rudu[i]) {
            q.push(-i);
        }
    }

    int no = 0;
    while(!q.empty()) {
        int v = -q.top();
        q.pop();
        result[++no] = v;
        for(int i = 0; i < top[v].size(); i++) {
            rudu[top[v][i]]--;
            if(!rudu[top[v][i]]) {
                q.push(-top[v][i]);
            }
        }
    }
    return ;
}
int check(int x) {
    build(x);
    return topo();
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int t;
        scanf("%d", &t);
        for(int j = 1; j <= t; j++) {
            int x;
            read(x);
            vec[i].push_back(x);
        }
    }
    int l = 1, r = m;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(check(mid)) {
            l = mid ;
        } else {
            r = mid - 1;
        }
    }

    find(l);
    // 打印结果
    for(int i = 1; i <= n; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}