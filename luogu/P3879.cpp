//
// Created by yangtao on 20-5-29.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
map<string, set<int> > mm;
string s;
int n, m;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> m;
        for(int j = 0; j < m; j++) {
            cin >> s;
            mm[s].insert(i);
        }
    }

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if ( mm.find(s) != mm.end() ) {
            set<int> t = mm[s];
            for(set<int>::iterator it = t.begin(); it != t.end(); it++ ){
                printf("%d ", *it);
            }
            printf("\n");
        } else {
            printf("\n");
        }
    }
    return 0;
}
