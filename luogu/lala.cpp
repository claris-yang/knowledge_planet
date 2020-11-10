//
// Created by yangtao on 20-10-28.
//
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
int n, cnt;
void merge(int l, int r) {
    for(int k = l; k <= r; k++ ) {
        b[k] = a[k];
    }
    int mid = l + r >> 1;
    int i = l , j = mid + 1;
    int idx = l;
    while(i <= mid && j <= r) {
        if( b[i] >= b[j] ) {
            a[idx++] = b[i++];
        } else {
            a[idx++] = b[j++];
            cnt += (mid - i + 1);
        }
    }
    while(i <= mid) {
        a[idx++] = b[i++];
    }
    while(j <= r) {
        a[idx++] = b[j++];
    }
}
void mergeSort(int l, int r) {
    if(l < r) {
        int mid = l + r >> 1;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, r);
    }
}
int main() {
    cin >> n;
    for(int i = 0 ; i < n; i++) {
        scanf("%d", &a[i]);

    }
    mergeSort(0, n);
    cout << cnt << endl;
    return 0;
}
