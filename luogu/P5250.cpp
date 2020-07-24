//
// Created by yangtao on 20-5-19.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
set<int> s;
int n;

int main() {
    cin >> n;
    for(int i = 0 ; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x == 1) {
            if(s.find(y) != s.end()) {
                printf("Already Exist\n");
            } else {
                s.insert(y);
            }
        } else {

            if(s.empty()) {
                printf("Empty\n");
            } else if( s.find(y) != s.end()) {
                printf("%d\n",y);
                s.erase(y);
            } else {
                set<int>::iterator p = s.lower_bound(y);
                set<int>::iterator a = p;
                if(p != s.begin()) p--;
                if( a != s.end() && y - *p >  *a - y )
                p = a;
                printf("%d\n", *p);
                s.erase(*p);

            }
        }
    }
    return 0;
}