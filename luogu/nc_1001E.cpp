//
// Created by yangtao on 20-5-25.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using  namespace std;
const int N = 5e5 + 5;
int a[N], b[N];
int n, cnt;
void merge(int l, int r) {
    int k = l;
    for(k = l ; k <= r; k++) {
        b[k] = a[k];
    }
    int mid = l + r >> 1;
    int i = l, j = mid + 1;
    k = l;
    while( i <= mid && j <= r) {
        if(b[i] <= b[j]) {
            a[k++] = a[i++];
        } else {
            a[k++] = b[j++];
            cnt+= mid - i + 1;
        }
    }
    while(i <= mid) {
        a[k++] = b[i++];
    }
    while(j <= r) {
        a[k++] = b[j++];
    }
}
void mergeSort(int l, int r) {
    if ( l < r) {
        int mid = l + r >> 1;
        mergeSort(l , mid);
        mergeSort(mid + 1, r);
        merge(l, r);
    }
}
int main() {
    while(1) {
        cin >> n;
        if(n==0) break;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        cnt = 0;
        mergeSort(0, n-1);
        cout << cnt << endl;
    }
    return 0;
}