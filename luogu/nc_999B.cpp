//
// Created by yangtao on 20-6-2.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
ll x, y;
int n;
int a[N], d[N];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 2; i <=n; i++) {
        d[i] = a[i] - a[i-1];
        if(d[i] > 0) x+=d[i]; else if (d[i] < 0 ) y-=d[i];
    }
    cout << max(x,  y) << endl;
    cout << abs(x - y) + 1 << endl;
    return 0;
}