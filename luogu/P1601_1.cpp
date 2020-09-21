//
// Created by yangtao on 20-8-28.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 505;
char s1[N], s2[N];
int d1[N], d2[N];
void add () {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    for(int i = 0; i < l1 ; i++) {
        d1[l1 - i - 1] = s1[i] - 48;
    }
    for(int i = 0; i < l2 ; i++) {
        d2[l2 - i - 1] = s2[i] - 48;
    }

    int l = max(l1, l2);
    for(int i = 0; i < l ; i++) {
        d1[i] += d2[i];
        if(d1[i] >= 10) {
            d1[i+1]++;
            d1[i]-=10;
        }
    }

    int t = l;
    for(; t > 0; t--) {
        if(d1[t]) break;
    }

    for(int i = t; i >= 0 ; i--) {
        printf("%d", d1[i]);
    }


}

int main() {
    cin >> s1 >> s2;
    add();
    return 0;
}