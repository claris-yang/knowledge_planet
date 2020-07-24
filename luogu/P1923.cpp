//
// Created by yangtao on 20-4-22.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 5000005;
int a[N];
int n, m;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);

    cout << a[m] << endl;
    return 0;
}