//
// Created by yangtao on 20-10-28.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
/*
 *  如果出价只剩下一个人， 那么肯定取这个人的最低价
 *  如果出价剩下大于1个人，倒数第二个人的最大价格的下一个价格。
 * */
using namespace std;
const int N = 2e6 + 5;
vector<int> v[N], d;
set<int> s;
int n, m, mmin[N], mmax[N];
int main() {
    cin >> n;
    memset(mmin, 0x3f, sizeof(mmin));
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        s.insert(x);
        mmin[x] = min(mmin[x], y);
        mmax[x] = max(mmax[x], y);
        v[x].push_back(y);
    }
    int t;
    cin >> t;
    while(t--) {
        cin >> m;
        d.clear();
        for(int i = 1; i <= m; i++) {
            int x;
            scanf("%d", &x);
            if(s.count(x)) {
                s.erase(x);
                d.push_back(x);
            }
        }
        if(s.size() == 0 ) {
            printf("%d %d\n", 0, 0);
        } else if(s.size() == 1) {
            auto x = s.begin();
            printf("%d %d\n", *x , mmin[*x]);
        } else if(s.size() > 1) {
            auto it2 = s.end();
            auto it1 = s.end();
            --it1; --it1; --it2;
            int last = mmax[*it1];
            auto it = upper_bound( v[*it2].begin(), v[*it2].end(), v[*it1].back());
//            if( it != v[*it2].end() )
                printf("%d %d\n", *it2, *it);
//            else {
//                printf("%d %d\n", *it2, mmax[*it2]);
//            }
        }

        for(int i = 0; i < d.size(); i++) {
            s.insert(d[i]);
        }
    }
    return 0;
}