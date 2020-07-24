//
// Created by yangtao on 20-5-19.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
map<string,int> m;
map<string,int>::iterator it;
int n;
string s;
int main() {
    cin >> n;
    for(int i =  0 ;i < n; i++) {
        cin >> s;
        it = m.find(s);
        if( it != m.end() ) {
            m[s] = it->second + 1;
        } else {
            m[s] = 1;
        }
    }
    cout << m.size() << endl;
    return 0;
}