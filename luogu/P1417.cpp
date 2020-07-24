//
// Created by yangtao on 19-10-15.
//

#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
struct Food {
    LL a, b, c;
    //bool operator<(const Food & f) const {
    //    return b * c < f.b * f.c;
    //}
};

bool cmp(Food a, Food b) {
    return a.b * a.c < b.b * b.c ;
}

Food a[100005];
LL dp[100005];
int main() {
    LL t, n , res = 0;
    cin >> t >> n;
    for(LL i = 1 ; i <= n; i++) {
        cin >> a[i].a;
    }
    for(LL i = 1 ; i <= n; i++) {
        cin >>  a[i].b ;
    }
    for(LL i = 1 ; i <= n; i++) {
        cin >> a[i].c ;
    }

    sort(a+1, a + n+1, cmp);

    for(LL i = 1 ;i <= n; i++) {
        for(LL j = t; j - a[j].c >= 0  ; j--) {
            //if( a[i].c <= j ) {
                dp[j] = max(dp[j], dp[j-a[i].c] + a[i].a - j * a[i].b);
            //}
        }
    }
    for(LL i =1 ;i <= t; i++) {
        res = max(res, dp[i]);
    }

    cout << res << endl;
    return 0;
}
