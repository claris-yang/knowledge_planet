//
// Created by yangtao on 20-4-3.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 500005;
char s1[N], s2[N];
int a[N], b[N], c[N];

void add(char a1[], char b1[], char c1[]) {
    int l1 = strlen(a1);
    int l2 = strlen(b1);

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));

    for(int i = 0 ; i < l1; i++) {
        a[l1 - i  - 1] = a1[i] - '0';
    }

    for(int i = 0; i < l2; i++) {
        b[l2 - i - 1 ] = b1[i] - '0' ;
    }

    int m = max(l1, l2);

    for(int i = 0; i < m; i++) {
        c[i] = a[i] + b[i];
        if(c[i] >= 10) {
            c[i+1] += 1;
            c[i] -= 10;
        }
    }

    int s = m;
    for( ; s > 0; s--) {
        if(c[s] != 0) break;
    }

    for( ; s > 0; s--) {
        printf("%d", c[s]);
    }


}
int main() {
    return 0;
}