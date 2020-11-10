//
// Created by yangtao on 20-10-19.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e4 + 4;
int l[N], r[N];
int n, lf, rf, ans;
int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &l[i], &r[i]);
    }

    for(int i = 1; i <= n; i++) {
        int lVal = 0 , rVal = 0;

        if(l[i-1] >= l[i] && l[i-1] <= r[i]) {
            lVal = min( abs(r[i] - r[i-1]), abs(r[i] - l[i-1]) );
            lf += (lVal + r[i] - l[i]);
        }

        if ( r[i-1] >= l[i] && r[i-1] <= r[i] ) {
            rVal = min( abs(l[i] - l[i-1]), abs(l[i] - r[i-1]) );
            rf += (rVal + r[i] - l[i]);
        }

        if (l[i - 1] <= l[i] ) {
            lf += (r[i] - l[i-1]);
        }

        if (r[i - 1] >= r[i]) {
            rf += (r[i-1] - l[i]);
        }

        cout << lf << " " << rf << endl;
    }

    ans = min(lf + n - l[n], rf + n - r[n]);
    cout << ans + n - 1 << endl;
    return 0;
}
