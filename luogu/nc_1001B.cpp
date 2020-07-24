//
// Created by yangtao on 20-6-1.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
int a[N];
int n;
int main() {
    cin >> n;
    for(int i = 1; i <=n ; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int res = 0;
    for(int i = 1;i <= n; i++) {
        if(n % 2 == 1) {
            res+= abs(a[i] - a[(n+1)/2]);
        } else {
            res+= abs(a[i] - a[n/2]);
        }
    }
    cout << res << endl;

    return 0;
}