//
// Created by yangtao on 20-8-27.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 30010;
int n, k, tot;
int a[N];
bool f[N];

int sort(int l, int r) {
    if(l == r && l == k) return a[k];
    if(l < r ) {
        int i = l, j = r, p = a[l];
        while(i < j) {
            while(i < j && a[j] > p) j--;
            if(i < j ) swap(a[i], a[j]);
            while(i < j && a[i] <= p ) i++;
            if(i <  j) swap(a[i], a[j]);
        }
        a[i] = p;
        if(i == k) return a[k];
        else if(i > k) return sort(l, i - 1);
        else return sort(i + 1, r);
    }
}

int main() {
    cin >> n >> k;
    int v;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v);
        if( !f[v]) {
            a[++tot] = v;
            f[v] = true;
        }
    }

    if(tot<k) {
        printf("NO RESULT");
        return 0;
    } else {
         printf("%d",sort(1,tot));
    }

    return 0;
}
