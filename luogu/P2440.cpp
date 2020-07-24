//
// Created by yangtao on 20-4-20.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
int a[N];
int n, k;
int l = 1, r, s;
int main() {
    cin >> n >> k;
    for(int i = 0 ; i < n; i++) {
        scanf("%d", &a[i]);
        r = max(a[i], r);
        s += a[i];
    }
    if( s < k) {
        cout << 0 << endl;
        return 0;
    }


    while(l < r) {
        int mid = l + r + 1 >> 1;

        int res = 0;
        for(int i = 0; i < n; i++) {
            res += a[i] / mid;
        }

        if( res >= k) {
            l = mid;
        } else {
            r = mid - 1 ;
        }
    }


    cout << l << endl;
    return 0;
}