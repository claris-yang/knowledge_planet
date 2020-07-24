//
// Created by yangtao on 20-4-26.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2505;

struct Cow {
    int low, high;
    bool operator<(const Cow &c) const {
        return low > c.low;
    }
};

struct SPFI {
    int val;
    int cover;
    bool operator<(const SPFI &s) const {
        return val > s.val;
    }
};
Cow a[N];
SPFI spfi[N];

int n, m;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++ ) {
        scanf("%d%d", &a[i].low, &a[i].high);
    }
    for(int i = 1; i <=m; i++) {
        scanf("%d%d", &spfi[i].val, &spfi[i].cover);
    }

    sort(a + 1, a + n + 1);
    sort(spfi + 1, spfi + m + 1);

    int res = 0;
    for(int i = 1; i<= n; i++) {
        for(int j = 0; j <= m; j++) {
            if( a[i].high >= spfi[j].val && a[i].low <= spfi[j].val && spfi[j].cover > 0) {
                res++, spfi[j].cover--;
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}