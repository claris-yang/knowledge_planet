//
// Created by yangtao on 19-7-22.
//

#include <iostream>
using namespace std;
int a[5000005];
int b[5000005];
long long  times = 0;
void merge(int l , int r) {
    int i, j, k;
    for(k = l;  k <= r; k++) {
        b[k] = a[k];
    }

    i = l;
    int mid = (l + r) / 2;
    j = mid + 1;
    k = l;
    while( i <= mid && j <= r) {
        if(b[i] <= b[j]) {
            a[k++] = b[i++];
        } else {
            a[k++] = b[j++];
            times += (mid - i + 1);
        }
    }

    while(i <= mid) {
        a[k++] = b[i++];
    }

    while(j <= r) {
        a[k++] = b[j++];
    }

}

void mergeSort(int l , int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, r);
    }
}
int main() {

    int n ;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort( 0 , n - 1);

    cout << times << endl;

    return 0;
}