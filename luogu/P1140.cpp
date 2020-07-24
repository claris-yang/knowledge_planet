//
// Created by yangtao on 19-11-12.
//

#include <iostream>
#include <cstring>
using namespace std;
const int N = 105;
int n1, n2;
int d[N][N];
char s1[N];
char s2[N];
int c[] = {};

int geti(char c) {
    if( c == 'A' )
        return 0;
    if( c == 'C' )
        return 1;
    if( c == 'G' )
        return 2;
    if( c == 'T' )
        return 3;
    if( c == '-' )
        return 4;
}

int d1[5][5] = {
        { 5, -1, -2, -1, -3},
        {-1,  5, -3, -2, -4},
        {-2, -3,  5, -2, -2},
        {-1, -2, -2,  5, -1},
        {-3, -4, -2, -1 , -1000}
};

int main() {
    cin >> n1 >> s1 ;
    cin >> n2 >> s2 ;
    memset(d, -1, sizeof(d));
    for(int i = 1; i <= n2; i++) {
        d[0][i] = d[0][i-1]+d1[4][geti(s2[i-1])];
    }
    for(int i = 1; i <= n1; i++) {
        d[i][0] = d[i-1][0] + d1[geti(s1[i-1])][4];
    }
    for(int i = 1 ; i <= n1; i++) {
        int c1 = geti(s1[i]);

        for(int j = 1; j <= n2; j++) {
            d[i][j] = 0 - 1e6;
            int c2 = geti(s2[j]);
            d[i][j] = max(max(d1[c1][c2] + d[i-1][j-1], d1[c1][4]+ d[i-1][j]) , d[i][j-1] + d1[4][c2]);
        }
    }
    cout << d[n1][n2];
    return 0;
}
