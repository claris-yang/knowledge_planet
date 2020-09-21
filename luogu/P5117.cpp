//
// Created by yangtao on 20-9-17.
//
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1005;
int d[N];
int n;
int main() {
    cin >> n;
    for(int i = 1; i <=n; i++) {
        int s, t , b;
        cin >> s >> t >> b;
        d[s] += b;
        d[t+1] -= b;
    }
    int ans = d[1];
    for(int i = 2; i < N; i++) {
        d[i] += d[i-1];
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}