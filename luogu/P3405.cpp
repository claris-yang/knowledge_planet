//
// Created by yangtao on 20-5-29.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1000;
int city[N][N];
int n;
int ans;
string c, s;
int main() {
    cin >> n;
    for(int i = 0 ; i < n; i++) {
        cin >> c >> s;
        int x = (c[0] - 'A') * 26 + c[1] - 'A';
        int y = (s[0] - 'A') * 26 + s[1] - 'A';
        if( x != y) {
            city[x][y]++;
            if(city[y][x]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}