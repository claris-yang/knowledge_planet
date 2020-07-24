//
// Created by yangtao on 20-4-27.
//

#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

void clear(priority_queue<int> &q) {
    priority_queue<int> empty;
    swap(empty, q);
}

int dd(int a, int b) {
    return a > b ? a - b : b - a;
}

priority_queue<int> big, small;
int n;
int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        while(scanf("%d",&n)) {
            if( n == 0 ) {
                break;
            } else if ( n == -1) {
                while( dd(big.size(), small.size()) > 1 ) {
                    if( big.size() > small.size() ) {
                        small.push(-big.top());
                        big.pop();
                    } else {
                        big.push(-small.top());
                        small.pop();
                    }
                }

                if(big.size() >= small.size()) {
                    printf("%d\n", big.top());
                    big.pop();
                } else {
                    printf("%d\n", -small.top());
                    small.pop();
                }

            } else {
                if(big.size() > 0 && n > big.top()) {
                    small.push(-n);
                } else {
                    big.push(n);
                }
            }
        }
    }

    return 0;
}