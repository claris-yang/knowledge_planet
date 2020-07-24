//
// Created by yangtao on 19-8-9.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a1[1000], b1[1000], c1[1000];
char a[1000], b[1000];
void add() {
    scanf("%s%s", a, b);
    int al = strlen(a);
    int bl = strlen(b);
    for(int i = 0; i < al; i++) {
        a1[al - i - 1] = a[i] - 48;
    }
    for (int i = 0; i < bl; ++i) {
        b1[bl - i - 1] = b[i] - 48;
    }
    int m = max(al, bl);
    for (int i = 0; i < m; ++i) {
        c1[i] += a1[i] + b1[i];
        if(c1[i] >= 10 ) {
            c1[i+1] = 1;
            c1[i] -= 10;
        }
    }

    int s = m ;
    for(; s > 0; s--) {
        if( c1[s] != 0) {
            break;
        }
    }
    for(int i = s; i >= 0; i--) {
        printf("%d", c1[i]);
    }
}
int main() {
    add();
    return 0;
}