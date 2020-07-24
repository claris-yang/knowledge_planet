//
// Created by yangtao on 20-6-3.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
string s;
int dfs(int l, int r) {

    if(l > r) return 0;

    for(int i = r; i > (l + r) / 2 ; i--) {
        string t = s.substr(i, r - i + 1);
        string h = s.substr(l, r - i + 1);
        if( t == h ) {
            cout << t << endl;
            return dfs( l + r - i + 1,  i-1) + 2;
        }
    }

    return 1;
}
int main() {
    cin >> s;
    cout << dfs(0 , s.length() - 1);
    return 0;
}