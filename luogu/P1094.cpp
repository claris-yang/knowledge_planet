//
// Created by yangtao on 20-5-15.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 3e4 + 5;
int a[N];
int w, n;
int l, r;
int res;
int main() {
    cin >> w >> n;
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a + n + 1);
    r = n,  l = 1;
    while(l <= r) {
        if(a[r] + a[l] <= w) {
            r--, l++;
        } else {
            r--;
        }
        res++;
    }
    cout << res << endl;
    return 0;

}