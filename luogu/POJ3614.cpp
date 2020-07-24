//
// Created by yangtao on 20-5-21.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2505;
struct Cow {
    int low;
    int high;
    bool operator<(const Cow & s) const {
        return low >= s.low;
    }
};

struct SPF {
    int v, cover;
    bool operator<(const SPF &s) const {
        return v > s.v;
    }
};

SPF spf[N];
Cow cow[N];
int n,m;
int cnt;
int main() {
    cin >> n ;
    getchar();
    cin >> m;
    for(int i = 0; i < n ; i++) {
        scanf("%d%d", &cow[i].low, &cow[i].high);
    }
    sort(cow, cow + n);

    for(int i = 0; i < m; i ++) {
        scanf("%d%d", &spf[i].v, &spf[i].cover);
    }

    sort(spf, spf+m);

    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(spf[j].cover <= 0) continue;
            if(cow[i].low <= spf[j].v && cow[i].high >= spf[j].v ) {
                cnt++, spf[j].cover--;
                break;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
