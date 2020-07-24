//
// Created by yangtao on 20-7-21.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
char a[N];
int next[N];
int t;
int main( ) {
    cin >> t;
    int idx = 1;
    while(idx <= t) {
        int n;
        cin >> n;
        scanf("%s", a+1);
        for(int i = 2, j = 0; i <= n; i++) {
            while(j && a[i] != a[j+1]) j = next[j];
            if(a[i] == a[j+1])  j++;
            next[i] = j;
        }

        printf("Test case #%d\n", idx++);
        for(int i = 2; i <= n; i++) {
            if(i % ( i - next[i]) == 0 && i / (i - next[i]) > 1) {
                printf("%d %d\n", i, i / (i - next[i]));
            }
        }
        puts("");
    }
    return 0;
}
