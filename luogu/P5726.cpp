//
// Created by yangtao on 20-4-30.
//

#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1005;
int mmin = 0x3f3f3f3f, mmax;
int n;
int ssum;
int main() {
    cin >> n;
    for(int i = 0 ; i < n; i++) {
        int t;
        cin >> t;
        ssum += t;
        mmin = min(t, mmin);
        mmax = max(t, mmax);
    }

    ssum -= mmax;
    if(n > 1) ssum -= mmin;

    printf("%.2lf", double(ssum) / (n - 2));

    return 0;
}