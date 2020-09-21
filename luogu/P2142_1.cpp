//
// Created by yangtao on 20-8-28.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100100;
char s1[N], s2[N];
int d1[N], d2[N], d3[N];
void dec() {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    for(int i = 0 ; i < l1 ; i++) {
        d1[l1 - i - 1] = s1[i] - 48;
    }
    for(int i = 0; i < l2; i++) {
        d2[l2 - i - 1] = s2[i] - 48;
    }
    int m = max(l1, l2);
    for(int i = 0 ; i < m ;i++) {
        d3[i] += d1[i] - d2[i];
        if( d3[i] < 0 ) {
            d3[i+1] -= 1;
            d3[i] += 10;
        }
    }
    if( d3[m] == -1 ) {
        memset(d3, 0, sizeof(d3));
        for(int i = 0 ; i < m ;i++) {
            d3[i] += d2[i] - d1[i];
            if(d3[i] < 0) {
                d3[i+1] -= 1;
                d3[i] += 10;
            }
        }
        cout << "-";
    }

    int n = m;
    for( ; n > 0 ; n-- ) {
        if( d3[n] ) break;
    }
    for(int i = n; i >= 0; i--) {
        printf("%d", d3[i]);
    }
}
int main() {
    cin >> s1 >> s2;
    dec();
    return 0;
}