//
// Created by yangtao on 20-5-21.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
const int N = 5e5 + 5;
ll a[N], b[N];
ll n, cnt;
void merge(ll l, ll r) {
    ll k;
    for(k = l; k <= r; k++) {
        b[k] = a[k];
    }
    ll i = l;
    ll mid = l + r >> 1;
    ll j = mid + 1;
    k = l;
    while(i <= mid && j <= r) {
        if(b[i] <= b[j]) {
            a[k++] = b[i++];
        } else {
            a[k++] = b[j++];
            cnt += (mid - i + 1);
        }
    }
    while(i <= mid) {
        a[k++] = b[i++];
    }
    while(j <= r) {
        a[k++] = b[j++];
    }
}
void merge_sort(ll l, ll r) {
    ll mid = l + r >> 1;
    if(l < r) {
        merge_sort(l , mid);
        merge_sort(mid + 1, r);
        merge(l, r);
    }
}
int main() {
    while(1) {
        scanf("%lld", &n);
        if(n == 0) break;
        for(int i = 0 ;i < n; i++) {
            scanf("%lld", &a[i]);
        }
        cnt = 0;
        merge_sort(0, n-1);
        printf("%lld\n", cnt);
    }
    return 0;
}