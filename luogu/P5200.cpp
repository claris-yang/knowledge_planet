//
// Created by yangtao on 20-10-30.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], tree[N], ans[N];
int lowbit(int x ) {
    return x & (-x);
}
void add(int x, int k) {
    for(int i = x; i <= n; i+= lowbit(i))
        tree[i] += k;
}
int query(int x ) {
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tree[i];
    return res;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int k = 0, sum = n;
    while(a[n-k] > a[n-k-1]) {
        add(a[n-k], 1);
        sum--;
        k++;
    }
    add(a[n-k], 1), sum--;
    for(int i = 1; i <= sum; i++) {
        add(a[i], 1);
        ans[i] = sum - i + query(a[i] - 1);
    }
    cout << sum << endl;
    for(int i = 1; i <= sum ;i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}