//
// Created by yangtao on 20-5-6.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int> small, big;
int n;
int main() {
    cin >> n;
    for(int i = 1 ; i <= n; i++) {
        int t;
        scanf("%d", &t);

        small.push(t);

        while( !small.empty() && !big.empty() && small.top() > -big.top() ) {
            big.push(-small.top());
            small.pop();
        }

        while( small.size() > 0 && small.size() - 1 > big.size() ) {
            big.push(-small.top());
            small.pop();
        }

        while( big.size() > 0 && big.size() > small.size() ) {
            small.push(-big.top());
            big.pop();
        }


        if( i % 2 == 1 ) {
            printf("%d\n", small.top());
        }
    }
    return 0;
}