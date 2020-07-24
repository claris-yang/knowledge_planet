//
// Created by yangtao on 20-5-21.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int n, k;
ll a[N];

int main() {
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i] += a[i-1];
    }

    ll res = 0;

    if( n < k ) {
        cout << 0 << endl;
        return 0;
    }


    for(int i = k; i < n; i++) {
        res = max(res, a[i] - a[i - k]);
    }

    cout << a[n-1] - res << endl;
    return 0;
}
