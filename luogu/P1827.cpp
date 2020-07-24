//
// Created by yangtao on 20-5-15.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
string s1, s2;
map<char, int> mm;
void dfs(int p1, int p2, int q1, int q2) {
    if(q1 > q2 || p1 > p2) return;
    char c = s2[q1];
    int p = mm[c];
    int l1 = p - p1;
    dfs(p1,    p - 1, q1 + 1, q1 +l1 );
    dfs(p + 1, p2, q1 + l1 + 1 , q2);
    cout << c ;
}
int main() {
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++) {
        mm[s1[i]] = i;
    }
    dfs( 0, s1.length() - 1, 0, s2.length() - 1);
    return 0;
}