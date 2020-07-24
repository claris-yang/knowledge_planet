//
// Created by yangtao on 20-4-22.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2000005;
int a[N];
int n, m;
void quickSort(int l, int r) {
    if (l >= r) return ;
    int i = l - 1, j = r+1, x = a[l+r>>1];
    while(i < j) {
        do i++; while(x > a[i]);
        do j--; while(x < a[j]);
        if(i < j ) swap(a[i], a[j]);
    }
    quickSort(l, j), quickSort(j+1, r);
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);

    }
    quickSort(1, m);
    for(int i = 1; i <= m; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}