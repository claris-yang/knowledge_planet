//
// Created by yangtao on 20-4-30.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int N = 10005;
int n, k;
int asum, bsum;
int acnt, bcnt;
int main() {
    cin >> n >> k;
    for(int i = 1;i <= n; i++) {
        if(i % k == 0) {
            asum += i;
            acnt++;
        } else {
            bsum += i;
            bcnt++;
        }
    }

    if(asum == 0) acnt++;
    if(bsum == 0) bcnt++;

    printf("%.1lf %.1lf", (double)asum / acnt, (double)bsum / bcnt);

    return 0;
}
