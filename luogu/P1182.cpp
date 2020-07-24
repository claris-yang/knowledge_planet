//
// Created by yangtao on 20-4-21.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int l, r;
int n, m;
int mmax, ssum;

int calc(int step) {
    int team = 0;
    int s = a[0];
    for(int i = 1; i < n; i++) {
        if(s + a[i] <= step) {
            s += a[i];
        } else {
            s = a[i];
            team++;
        }
    }
    return team;
}

int main() {
    cin >> n >>m;
    for(int i = 0 ; i < n; i++) {
        scanf("%d", &a[i]);
        mmax = max(mmax, a[i]);
        ssum += a[i];
    }

    l= mmax, r = ssum;
    while(l <= r) {
        int mid = l + r >> 1;
        int team = calc(mid);
        if(team < m) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;

    return 0;
}
