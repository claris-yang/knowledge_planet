//
// Created by yangtao on 20-6-29.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 51000100;
int p[N], mx, id;
char str[N];
int res = -1;
int init() {
    int len = 1;
    str[0] = '@', str[1] = '*';
    while( 1 ) {
        char c = getchar();
        if(c < 'a' || c > 'z' ) break;
        str[++len] = c;
        str[++len] = '*';
    }
    return len;
}
void manacher() {
    int len = init();
    for(int i = 1; i < len; i++) {
        if(i < mx) p[i] = min(p[2 * id - i] , mx - i);
        else p[i] = 1;
        while( str[p[i] + i] == str[i - p[i]]) p[i]++;
        if(p[i] + i > mx) mx = p[i] + i, id = i;
        res = max(res, p[i] - 1);
    }
}
int main() {

    manacher();
    cout << res;
    return 0;
}
