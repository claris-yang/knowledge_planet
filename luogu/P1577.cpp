//
// Created by yangtao on 20-8-27.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;
const int N = 100005;

int n , k;
int a[N];

bool check(int v ) {

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += a[i] / v;
    }

    return ans >= k;
}
int main( ) {
    cin >> n >> k;

    for(int i = 1; i <=n; i++)  {
        double t;
        scanf("%lf", &t);
        a[i] = int(t * 100);
    }
    int l = 0, r = 1 << 30;

    while(l <= r) {
        int mid = (l + r) / 2;
        if(mid == 0) break;
        if( check(mid) ) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    printf("%.2f", (double)l / 100);
    return 0;

}