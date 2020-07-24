//
// Created by yangtao on 20-4-30.
//

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll a[N], t[N];
ll n, times;

void merge(ll l, ll r) {
    // 备份原数组
    for(int i = l ; i <= r; i++) t[i] = a[i];
    ll mid = l + r >> 1;
    ll i = l, j = mid + 1;
    ll k = l;
    while(i <= mid && j <= r) {
        if(t[i] <= t[j]) {
            a[k++] = t[i++];
        } else {
            times += mid - i + 1;
            a[k++] = t[j++];
        }
    }
    while(i <= mid ) {
        a[k++] = t[i++];
    }
    while(j <= r) {
        a[k++] = t[j++];
    }
}
void mergeSort(ll l , ll r ) {
    if (l >= r) return ;
    ll mid = l + r >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, r);
}

int main() {

    while(1) {
        cin >> n;
        if(!n) break;
        for(int i = 1 ;i <=n ; i++) {
            scanf("%lld", &a[i]);
        }

        // 次数清0
        times = 0;
        mergeSort(1, n);
        printf("%lld\n", times);

    }
    return 0;
}