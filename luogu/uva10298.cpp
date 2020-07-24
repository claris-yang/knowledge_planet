//
// Created by yangtao on 20-7-21.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6;
char a[N];
int nxt[N];
int main() {
    while(1) {
        scanf("%s", a + 1);
        if(!strcmp(a + 1, ".")) break;
        nxt[1] = 0;

        int n = strlen(a + 1);
        for(int i = 2, j = 0; i <= n; i++) {
            while(j && a[j+1] != a[i]) j = nxt[j];
            if( a[i] == a[j+1]) j++;
            nxt[i] = j;
        }

        if( n % (n - nxt[n]) == 0 ) {
            printf("%d\n",  n / (n - nxt[n]) );
        } else {
            printf("%d\n", 1);
        }
    }
    return 0;
}