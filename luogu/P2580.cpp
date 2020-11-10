//
// Created by yangtao on 20-11-8.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
map<string, int> mm;
int n ,m;
string s;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        mm[s] = 0;
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> s;
        if(!mm.count(s)) {
            cout << "WRONG" << endl;
        } else if( mm[s] == 0 ) {
            cout << "OK" << endl;
            mm[s]++;
        } else {
            cout << "REPEAT" << endl;
        }
    }
    return 0;
}
