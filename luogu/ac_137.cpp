//
// Created by yangtao on 20-10-12.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int P = 131;
typedef unsigned long long ull;
unordered_set<ull> s;
int a[10];
ull h[15];
int n;
bool make_hash() {
    ull v ;
    for(int i = 1; i <= 6; i++) {
        v = 0 ;
        for(int j = 0; j < 6; j++) {
            v = v * P + a[i + j];
        }
        h[i] = v;
    }
    for(int i = 1; i <= 6; i++) {
        if(s.find(h[i]) != s.end()) {
            return true;
        }
    }
    s.insert(v);

    return false;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 6; j++) {
            scanf("%d", &a[j]);
            a[j + 6] = a[j];
        }
        if(make_hash()) {
            cout << "Twin snowflakes found." << endl;
            return 0;
        }
        for(int i = 1; i <= 6; i++) {
            swap(a[i], a[12 - i + 1]);
        }
        if(make_hash()) {
            cout << "Twin snowflakes found." << endl;
            return 0;
        }
    }
    cout << "No two snowflakes are alike." << endl;
    return 0;
}