//
// Created by yangtao on 20-4-13.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N], c[N] ;
int bucket[N];
int n, l, r, cnt;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        bucket[a[i]] = i;
    }
    for(int i =1; i <=n ; i++) {
        scanf("%d", &b[i]);
        c[i] = bucket[b[i]];
    }

    for(int i = 1; i <=n; i++) {
        if( c[i] > a[cnt]) {
            a[++cnt] = c[i];
        } else {
            l = 1, r = cnt;
            int p = 0;
            while(l <= r) {
                int mid = l + r >> 1;
                if ( a[mid] >= c[i]) {
                    p = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            a[l] = c[i];
        }
    }

    cout << cnt << endl;
    return 0;
}