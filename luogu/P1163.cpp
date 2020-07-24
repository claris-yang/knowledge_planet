//
// Created by yangtao on 20-6-1.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
double x, y, z;
bool calc( double d ) {
    double p = pow( 1.0 / (1.0 + d), z);
    return p >= 1 - x/y*d;
}
int main() {
    cin >> x >> y >> z;
    double l = 0 , r = 10;
    while(r - l >= 0.0001) {
        double mid = (l + r) / 2;
        if( calc(mid) ) r = mid; else l = mid ;
    }
    printf("%.1f\n", l * 100);
    return 0;
}