//
// Created by yangtao on 20-5-21.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int n, m;

priority_queue<int> big, small;
int main() {
    cin >> m >> n;

    for(int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }

    int j = 1;
    for(int i = 1; i <= n; i++) {
        int d;
        scanf("%d", &d);
        for(j ; j <= d; j++) {
            big.push(a[j]);
            if(big.size() == i) small.push(-big.top()), big.pop();
        }
        printf("%d\n", -small.top());
        big.push(-small.top()), small.pop();
    }

    return 0;
}