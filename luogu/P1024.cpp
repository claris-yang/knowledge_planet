//
// Created by yangtao on 20-4-20.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const double N = 0.001;
double a, b, c, d;
int s;
double l = -100, r = 100;
double dabs(double x) {
    if (x < 0) {
        return -x;
    }
    return x;
}
double calc(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}
int main() {
    cin >> a >> b >> c >> d;

    for(int i = -100; i < 100; i++) {
        double l = i;
        double r = i + 1;
        double lv = calc(l);
        double rv = calc(r);
        if( !lv ) {
            printf("%.2lf ", l);
            s++;
            continue;
        }

        if(lv * rv < 0 ){
            while ( (r - l ) > N ) {
                double mid = (l + r) / 2;
                if( calc(mid) * calc(l) < 0 ) {
                    r = mid;
                } else {
                    l = mid;
                }

            }
            printf("%.2lf ", r);
            s++;
        }

        if (s >= 3) break;
    }
    return 0;
}