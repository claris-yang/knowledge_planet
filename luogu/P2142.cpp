//
// Created by yangtao on 19-8-9.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 100100
using namespace std;
char a[MAXN], b[MAXN];
int a1[MAXN], b1[MAXN], c1[MAXN];
int jian() {
    scanf("%s%s", a, b);
    int al = strlen(a);
    int bl = strlen(b);
    for(int i = 0 ; i < al; i++) {
        a1[al - i - 1] = a[i] - 48;
    }
    for (int i = 0; i < bl; ++i) {
        b1[bl - i - 1] = b[i] - 48;
    }
    int m = max(al, bl);
    for(int i = 0; i < m ; i++) {
        c1[i] += a1[i] - b1[i];
        if( c1[i] < 0 ) {
            c1[i+1]--;
            c1[i] += 10;
        }
    }
    if(c1[m] == -1) {
        memset(c1, 0, sizeof(c1));
        for( int i = 0 ; i < m ;i++) {
            c1[i] += b1[i] - a1[i];
            if( c1[i] < 0) {
                c1[i+1]--;
                c1[i] += 10;
            }
        }
        printf("-");
    }
    int s = m ;
    for(; s > 0; s--) {
        if(c1[s] != 0) {
            break;
        }
    }
    for(int i = s; i >=0 ; i--) {
        printf("%d", c1[i]);
    }
}
int main() {
    jian();
    return 0;
}