//
// Created by yangtao on 19-11-1.
//


#include <iostream>
#include <cstdio>
using namespace std;
int hh, mm, x;
int t = 0;
int cc[24][60];
char c;


bool ishuiwen(int a, int b) {
    if(a == 0 && b == 0) return true;

    if( a >= 10 && b >= 10 )
        if(a % 10 == b / 10 && a / 10 == b % 10) return true;

    if(a >= 10 && b < 10) {
        if(a % 10 == 0 && a / 10 == b)  return true;
    }
    if(b >= 10 && a < 10) {
        if(b % 10 == 0 && b / 10 == a) return true;
    }
    return false;
}

void next_time(int &hh, int &mm) {

    int t = x;
    for(int i = hh; ; i--) {
        for(int j = mm; j >= 0; j--) {

            if(t == 0) {
                hh = i, mm= j;
                return ;
            }
            t--;
        }
        mm = 59;
        if(i == 0) i = 24;
    }
}
int main() {
    cin >> hh >> c >> mm >> x;
    x %= 86400;

    while(!cc[hh][mm]) {
        cc[hh][mm] = 1;
        if(ishuiwen(hh, mm)) {
            printf("%02d:%02d\n", hh, mm);
            cout << t << endl;
            return 0;
        }
        next_time(hh, mm);
        t++;
    }

    cout << "No Solution";

    return 0;
}