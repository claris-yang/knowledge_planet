//
// Created by yangtao on 20-8-6.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10;
const int INF = 0x3f3f3f3f;
int d[N];
int a, b, c, x, y, z;
struct Node {
    int a[N];
    bool operator != (const Node & node) {
        for(int i = 1; i <= 3; i++) {
            if( a[i] != node.a[i]) return true;
            else return false;
        }
    }
};

Node getfa(int a[], int k) {
    Node ans;
    int d1 = a[2] - a[1], d2 = a[3] - a[2];
    for(int i = 1; i <= 3; i++) ans.a[i] = a[i];
    if(d1 == d2 ) return ans;
    if(d1 < d2) {
        int t = min(k, (d2 - 1) / d1);
        k -= t;
        temp += t;
        ans.a[2] += t * d1, ans.a[1] += t * d1;
    } else {
        int t = min(k, (d1 - 1) / d2);
        k -= t;
        temp += t;
        ans.a[2] -= t * d2, ans.a[3] -= t * d2;
    }
    if(k) return getfa(ans.a, k);
    else return ans;
}
int main() {
    for(int i = 1; i <= 3; i++) {
        cin >> d[i];
    }
    sort(d + 1, d + 3 + 1);
    a = d[1], b = d[2], c = d[3];

    for(int i = 1; i <= 3; i++) {
        cin >> d[i];
    }
    sort(d + 1, d + 3 + 1);
    x = d[1], y = d[2], z = d[3];


    if()
}
