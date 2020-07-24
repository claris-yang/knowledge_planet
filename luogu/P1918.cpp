//
// Created by yangtao on 20-5-21.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e5 + 5;
int n, m;
map<int, int> s;
map<int, int>::iterator it;
int main() {
    cin >> n;
    for(int i =  1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        s[t] = i;
    }
    cin >> m;
    for(int i = 0 ;i < m; i++) {
        int q;
        scanf("%d", &q);
        it = s.find(q);
        if(it != s.end()) {
            printf("%d\n", it->second);
        } else {
            printf("0\n");
        }
    }
    return 0;
}