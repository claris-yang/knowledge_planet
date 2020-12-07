//
// Created by yangtao on 20-10-27.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
const int N = 10000005;
set<pair<int, int> > s;
int mmax[N], vis[N];
vector<int> v[N];
int n, m, t;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        mmax[x] = max(mmax[x], y);
        vis[x] = 1;
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i]) {
            s.insert(make_pair(mmax[i], i));
        }
    }

    cin >> t;
    while(t--) {
        cin >> m;
        vector<int> d;
        for(int i = 1; i <= m; i++ ) {
            int x;
            scanf("%d", &x);
            s.erase(make_pair(mmax[x], x));
            d.push_back(x);
        }

        if( s.size() == 0) {
            printf("%d %d\n",0, 0);
        } else if( s.size() == 1) {
            printf("%d %d\n", s.begin()->second, *v[s.begin()->second].begin());
        } else {
            auto p1 = s.end();
            auto p2 = p1;
            p1--, p1--, p2--;
            auto val = upper_bound(v[p2->second].begin(), v[p2->second].end(), p1->first);
            printf("%d %d\n", p2->second, *val);
        }
        for(int i = 0; i < d.size(); i++) {
            s.insert(make_pair(mmax[d[i]], d[i]));
        }
    }
    return 0;
}
