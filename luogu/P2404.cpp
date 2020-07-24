//
// Created by yangtao on 20-5-9.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char c[10];

int N;
void dfs(int n, int b) {
 //   cout << "beijing" << n << endl;
    if(n <= 1) {
        for(int i = 1; i < b - 1; i++) {
            printf("%d+", c[i] - '0');
        }
        printf("%d\n", c[b-1] - '0');
    }
    for(int i = 1; i <= n / 2; i++) {
        c[b] = i + '0';
        dfs(n - i, b + 1);
    }

    if(N - n / 2 > 0 ) {
        for(int i = 1; i <= n / 2; i++) {
            printf("%d+", c[i] - '0');
        }
        printf("%d\n", n);
    }
}
int main() {
    int n ;
    cin >> n;
    N = n;
    dfs(n , 1);
    return 0;
}
