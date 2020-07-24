//
// Created by yangtao on 20-6-9.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
string s;

unordered_map<string, int> m;
const int N = 1e5;
string ss[20005];
int e[N], ne[N], h[N], idx, num;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

int dfs( int x ) {
    int y = x;
    for(int i = h[x]; ~i; i = ne[i]) {
        int v = e[i];
        y = dfs(v);
    }
    return y;
}
int main() {
    memset(h, -1, sizeof(h));
    int u, v;
    while(1) {
        cin >> s;
        if(s[0] == '#') {
            s = s.substr(1, s.length());
            if( m.find(s) == m.end()) {
                v = num;
                ss[num] = s;
                m[s] = num++;
            } else {
                v = m[s];
            }
        } else if (s[0] == '+') {
            s = s.substr(1, s.length());
            if( m.find(s) == m.end()) {
                u = num;
                ss[num] = s;
                m[s] = num++;
            } else {
                u = m[s];
            }
            add(u, v);
        } else if( s[0] == '?' ) {
            s = s.substr(1, s.length());
            int y = dfs(m[s]);
            cout << s << " " << ss[y] << endl;
        } else if ( s[0] == '$') {
            break;
        }
    }
    return 0;
}