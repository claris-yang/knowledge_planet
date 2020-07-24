//
// Created by yangtao on 20-4-26.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 100005;
int size = 0, size1 = 0;
int n;
int h[N], h1[N];

void down(int u) {
    int t = u;
    if( u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    if( u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if( u != t) {
        swap(h[u], h[t]);
        down(t);
    }
}

void up(int u) {
    while(u / 2 && h[u] < h[u/2]) {
        swap(u, u/2);
        u >>= 1;
    }
}

void down1(int u) {
    int t = u;
    if( u * 2 <= size && h1[u * 2] < h1[t]) t = u * 2;
    if( u * 2 + 1 <= size && h1[u * 2 + 1] < h1[t]) t = u * 2 + 1;
    if( u != t) {
        swap(h1[u], h1[t]);
        down1(t);
    }
}

void up1(int u) {
    while(u / 2 && h1[u] < h1[u/2]) {
        swap(u, u/2);
        u >>= 1;
    }
}

void add(int t) {
    if( n % 2 == 1) {
        h1[++size1] = t;
        up1(size1);
    } else {
        h[++size] = h1[1];
        up(size);
        h1[1] = h1[size--];
        down1(1);
    }
    n++;
}

void pop() {
    if(size1 == size) {
        int small = h1[1];
        int big = h[1];
        if(small < big) {
            printf("%d\n", small);
        } else {
            printf("%d\n", big);
        }
    }
}

void calc(int t) {
    if(t == -1) {
        pop();
    } else {
        add(t);
    }
}

int main() {

    int t;
    while( scanf("%d", &t) ) {
        if(t == 0) {
            init();
        } else {
            calc(t);
        }
    }
    return 0;
}