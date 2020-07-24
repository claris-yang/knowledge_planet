//
// Created by yangtao on 20-6-10.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1005;
int in[N], out[N], vis[N];
string s[N];
vector<string> v;
int n;
int find_start() {
    for(int i = 0; i < n; i++) {
        if( in[s[i][0]] == out[s[i][0]] + 1 ) {
            return i;
        }
    }
    return 0;
}

bool dfs() {
    if(v.size() >= n) return true;
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        string last = v.back();
        if( last[last.length()-1] == s[i][0] ) {
            vis[i] = 1;
            v.push_back(s[i]);
            if( dfs() ) return true;
            v.pop_back();
            vis[i] = 0;
        }
    }
    return false;
}

int main() {

    cin >> n;
    for(int i = 0  ; i < n; i++) {
        cin >> s[i];
        in[s[i][0]]++, out[s[i][s[i].length()-1]]++;
    }
    sort(s , s + n);

    int p = find_start();
    vis[p] = 1, v.push_back(s[p]);

    if(dfs()) {
        for(int i = 0 ;i < v.size() - 1 ; i ++) {
            cout << v[i] << ".";
        }
        cout << v.back();
    } else {
        cout << "***" << endl;
    }

    return 0;
}