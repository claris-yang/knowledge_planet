//
// Created by yangtao on 20-8-3.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e6 + 5;
int a[N], in[N];
int n, cnt;
queue<int> q;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        in[a[i]]++;
    }

    for(int i = 1; i <=n; i++) {
        if(!in[i]) q.push(i);
    }

    while( q.size()) {
        int v = q.front();
        q.pop();
        in[a[v]]--;
        if(!in[a[v]]) q.push(a[v]);
    }

    for(int i = 1; i <=n; i++) {
        if(in[i]) cnt++;
    }

    cout << cnt << endl;

    return 0;

}