//
// Created by yangtao on 20-6-4.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 200005;
PII a[N];
int n;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i].first = x;
        a[i].second = i;
    }
    sort(a, a + n);
    int last = INT_MAX, dir = -1, res = 1;
    for(int i = 0 ;i < n; ) {
        int j = i;
        while(j < n && a[j].first == a[i].first) j++;
        int l = i , r = j ;
        if( dir == - 1) {
            if( last < r ) {
                dir = 1; last = r;
            } else {
                last = r;
            }
        } else {
            if (last < l ) {
                last = r;
            } else {
                last = r, dir = -1, res++;
            }
        }
        i = j;
    }
    cout << res << endl;
    return 0;
}