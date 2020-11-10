//
// Created by yangtao on 20-10-23.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 505;
int n,f[N];
void init() {
    for(int i = 1; i <=n; i++) f[i] = i;
}

int find(int x) {
    if(f[x] != x ) f[x] = find(f[x]);
    return f[x];
}
void merge(int x, int y) {
    f[find(x)] = find(y);
}

string s;
int main() {
    cin >> n;
    init();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char t;
            cin >> t;
            if(t == '1') {
                merge(i, j);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(find(i) == find(j)) {
                cout << 1 ;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
    return 0;
}