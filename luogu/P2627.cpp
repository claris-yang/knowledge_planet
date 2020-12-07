//
// Created by yangtao on 20-11-26.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 100005;
ll sum[N], q[N], d[N], dp[N];
int n, m, head = 0, tail = 1;
ll que(int i) {
    d[i] = dp[i-1] - sum[i];
    while(head <= tail && d[q[tail]] < d[i]) tail--;
    q[++tail] = i;
    while(head <= tail && q[head]<i-m) head++;
    return d[q[head]];
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &sum[i]);
        sum[i] += sum[i-1];
    }
    for(int i = 1; i <= n; i++) {
        dp[i] = que(i) + sum[i];
    }
    cout << dp[n];
    return 0;
}
