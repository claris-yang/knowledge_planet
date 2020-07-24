//
// Created by yangtao on 20-5-25.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2505;
struct Cow{
    int low, high;
    bool operator<(const Cow &c) const {
        return low > c.low;
    }
};
struct SPF {
    int v, c;
    bool operator<(const SPF &s) const {
        return v > s.v;
    }
};
Cow cow[N];
SPF spf[N];
int n,m, cnt;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &cow[i].low, &cow[i].high);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &spf[i].v, &spf[i].c);
    }
    sort(cow, cow+n);
    sort(spf, spf+m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(spf[j].c <= 0) continue;
            if(cow[i].low <= spf[j].v && cow[i].high >= spf[j].v) {
                spf[j].c--;
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
