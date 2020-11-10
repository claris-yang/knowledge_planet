//
// Created by yangtao on 20-10-27.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int N = 10000005;
unordered_set<int> no;
struct Node {
    int no, val;
}a[N];
int n, m, t;
unordered_map<int, int> mmin, mmax;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i].no = x;
        a[i].val = y;
        if( !no.count(x)) {
            mmin[x] = y;
        }
//        else {
//            mmax[x] = max(mmax[x], y);
//        }
        no.insert(x);
    }
    cin >> t;
    while(t--) {
        cin >> m;
        unordered_set<int> s(no);
        for(int i = 1; i <= m; i++ ) {
            int x;
            scanf("%d", &x);
            s.erase(x);
        }

        if( s.size() == 0) {
            printf("%d %d\n",0, 0);
        } else if( s.size() == 1) {
            printf("%d %d\n", *s.begin(), mmin[*s.begin()]);
        } else {
            for(int i = n ; i >= 1; i--) {
                if(s.count(a[i].no)) {
                    printf("%d %d\n", a[i].no, a[i].val);
                    break;
                }
            }
        }
    }
    return 0;
}
