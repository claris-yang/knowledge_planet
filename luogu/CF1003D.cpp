//
// Created by yangtao on 20-11-8.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
map<int, int>mm;
int n, m;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        mm[t]++;
    }
    for(int i = 1; i <= m; i++) {
        int b ;
        cin >> b;
        int cnt = 0;
        if(!mm.size()) {
            cout << -1 << endl;
            continue;
        }

        auto it = mm.end();
        it--;
        while(1) {
            int mmin = min( b / it->first, it->second );
            b -= it->first * mmin;
            cnt += mmin;
            if( !b ) {
                cout << cnt << endl;
                break;
            }
            if(it == mm.begin() && b) {
                cout << -1 << endl;
                break;
            }
            it--;
        }
    }
    return 0;
}