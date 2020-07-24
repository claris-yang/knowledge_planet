//
// Created by yangtao on 20-6-11.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int  N = 1e5 + 5;
int n, p;
double tot;
double a[N], b[N];
double l = 0, r = 1e10;
bool check(double m) {
    double dsum = m * p;
    double sum = 0;
    for(int i = 0 ;i < n; i++) {
        if(b[i] >= a[i] * m) continue;
        sum += (m * a[i] - b[i]);
    }
    return dsum >= sum ;
}
int main() {
    cin >> n >> p;
    for(int i = 0; i < n ; i++) {
        cin >> a[i] >> b[i];
        tot+=a[i];
    }

    if( tot <= p ) {
        cout << -1 ;
        return 0;
    }

    while( r - l > 1e-6 ) {
        double mid = (r + l) / 2;
        if( check(mid) ) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.10lf", l);
    return 0;
}
