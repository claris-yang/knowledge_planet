//
// Created by yangtao on 20-8-11.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef  long long ll;
const int N = 1e5 + 5;
int n, p;
int cnt5[N], cnt2[N];
ll f[205][N], a[N];
int main() {
    cin >> n >> p;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        ll t = a[i];

        while( t % 5 == 0 )  cnt5[i]++, t /= 5;
        while( t % 2 == 0 )  cnt2[i]++, t /= 2;
    }

    memset(f, -0x3f, sizeof(f));
    f[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        // 倒序, 需要用到n-1次的结果
        for(int j = p ; j >= 1; j--) {
            //
            for(int k = cnt5[i]; k <= 6000; k++) {
                f[j][k] = max(f[j][k] , f[j-1][k - cnt5[i]] + cnt2[i]);
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i <= 6000; i++ ) {
        ans = max(ans, min(f[p][i], (ll)i));
    }

    cout << ans << endl;
    return 0;
}
