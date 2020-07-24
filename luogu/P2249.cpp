//
// Created by yangtao on 20-4-8.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 1e6 + 5;
int a[N];
int n, m;

using  namespace std;
int search(int x) {
    int l = 1, r = n;
    while(l < r ) {
        int mid = (l + r) >> 1;
        if(x <= a[mid] ) {
            r = mid ;
        } else  {
            l = mid + 1;
        }
    }

    return a[l] == x ? l : -1;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <=m ; i++) {
        int x;
        scanf("%d", &x);
        printf("%d " , search(x));
    }
    return 0;
}