//
// Created by yangtao on 20-10-27.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
map<int, int > m;
int n;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        if(m.count(t)) {
            m[t]++;
        } else {
            m[t] = 1;
        }
    }
    map<int, int>::iterator it = m.begin();
    for(; it != m.end(); it++) {
        printf("%d %d\n", (*it).first, (*it).second );
    }
    return 0;

}
