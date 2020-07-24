//
// Created by yangtao on 20-4-8.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef  long long ll ;
const int N = 2e5+5;
int a[N];
int n, c;
ll res;
int searchl(int l, int r, int c) {
    while(l < r) {
        int mid = (l + r) >> 1;
        if(c <= a[mid]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int searchr(int l , int r, int c ) {
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if( c >= a[mid]) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

int main() {
    cin >> n >> c;
    for(int i = 1; i <=n ;i++) {
        scanf("%d", &a[i]);
    }
    if(c < 0) c = -c;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        int l = searchl(i + 1, n,  a[i] + c);
        if(a[l] == a[i] + c) {
            res += (ll)searchr(i + 1, n, a[i] + c ) - l  + 1;
        }
    }

    cout << res << endl;
    return 0;
}