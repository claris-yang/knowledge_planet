//
// Created by yangtao on 20-6-28.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
ll a[N], d[N];
ll n;
ll x, y;
int main() {
    cin >> n;
    for(int i = 1; i <=n; i++) {
        scanf("%lld", &a[i]);
        d[i] = a[i] - a[i-1];
    }

    for(int i = 2; i<=n; i++) {
        if( d[i] > 0) {
            x += d[i];
        }  else if(d[i] < 0) {
            y -= d[i];
        }
    }


    cout << max(x,  y) << endl;
    cout << abs(x - y) + 1 << endl;
    return 0;
}