//
// Created by yangtao on 20-8-1.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100005;
int f[N], a[N];
int n, idx;
int main() {
    while( EOF != scanf("%d", &a[++n]));

    f[0] = 0x3f3f3f3f;
    for(int i = 1; i < n; i++) {
        if( a[i] <= f[idx])
            f[++idx] = a[i];
        else {
            int l = 1, r = idx , t = l;
            while(l <= r) {
                int mid = l + r >> 1;
                if( f[mid] < a[i] ) {
                    t = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            f[t] = a[i];
        }
    }
    cout << idx << endl;

    memset(f, 0, sizeof(f));
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if( a[i] > f[ans] ) {
            f[++ans] = a[i];
        } else {
            int l = 1, r = ans, t = l;
            while(l <= r) {
                int mid = l + r >> 1;
                if( f[mid] >= a[i] ) {
                    t = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            f[t] = a[i];
        }
    }

    cout << ans << endl;
    return 0;
}
