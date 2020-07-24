//
// Created by yangtao on 19-11-6.
//

#include <bits/stdc++.h>
using namespace std;
char  s1[200] , s2[200] ;
int k, s;
int step;

int ch(char c) {
    if( c >= 'A' && c <= 'F' ) {
        return c - 'A' + 10;
    }
    return c - '0';
}

char nu(int n) {
    const char d[] = "0123456789ABCDEF";
    return d[n];
}

bool isHuiWen() {
    int l = 0, r = strlen(s1) - 1;
    while(l < r) {
        if(s1[l] != s1[r] ) return false;
        l++, r--;
    }
    return true;
}

void add() {

    int t = 0;
    int l = strlen(s1);

    int a, b;
    for(int i = 0 ; i < l ; i++) {
        int a = ch(s1[i]), b = ch(s1[l-i-1]);
        s2[i] = nu(( a+b+t ) % k);
        t = (a+b+t) / k;
    }

    if(t > 0) {
        s2[l] = nu(t);
    }

    l = strlen(s2);
    for(int i = 0 ;i < l ; i++) {
        s1[i] = s2[l - i - 1];
    }

}

int main()
{
    cin >> k >> s1;
    reverse(s1, s1 + strlen(s1));
    while(step <= 30) {
        if(isHuiWen()) {
            printf("STEP=%d\n", step);
            return 0;
        }
        add();
        step++;
    }
    puts("Impossible!");

    return 0;
}