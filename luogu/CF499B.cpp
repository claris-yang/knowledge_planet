//
// Created by yangtao on 20-11-8.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
map<string, string> mm;
int n , m;
string s1, s2;
int main() {
    cin >> n >> m;
    for(int i = 1 ; i <= m; i++) {
        cin >> s1 >> s2;
        mm[s1] = s2;
    }
    for(int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        if( t.length() <= mm[t].length() ) {
            cout << t << " " ;
        } else {
            cout << mm[t] << " ";
        }
    }
    return 0;
}
