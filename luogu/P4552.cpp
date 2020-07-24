//
// Created by yangtao on 20-4-24.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
typedef long long ll;
int a[N], b[N];
ll x, y;
int n;
ll myabs(ll a) {
    if ( a >= 0 ) {
        return a ;
    } else {
        return -a;
    }
}

ll min(ll a, ll b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 2; i <= n; i++) {
        b[i] = a[i] - a[i-1];
        if( b[i] > 0 ) x+=b[i];
        if( b[i] < 0 ) y-=b[i];
    }

    ll res = min(x , y);

    cout << res + myabs(x-y) << endl << myabs(x-y) + 1 << endl;

    return 0;
}