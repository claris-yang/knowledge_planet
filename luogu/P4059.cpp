//
// Created by yangtao on 2020/11/2.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 3005;
char s1[N], s2[N];
int d[10][10], a, b, ans = -0x3f3f3f3f;
int dp1[N][N], dp2[N][N], dp3[N][N];

int get(char c) {
    switch (c) {
        case 'A' : return 1;
        case 'T' : return 2;
        case 'G' : return 3;
        case 'C' : return 4;
    }
    return 0;
}

int main() {
    cin >> s1 + 1 >> s2 + 1;
    int len1 = strlen(s1 + 1);
    int len2 = strlen(s2 + 1);
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++ ) {
            cin >> d[i][j];
        }
    }
    cin >> a >> b;
    memset(dp1, -0x3f, sizeof(dp1));
    memset(dp2, -0x3f, sizeof(dp2));
    memset(dp3, -0x3f, sizeof(dp3));
    dp1[0][1] = dp2[1][0] = -a;
    dp1[0][0] = dp2[0][0] = dp3[0][0] = 0 ;
    for(int i = 2; i <= len1; i++) {
        dp2[i][0] = dp2[i-1][0] - b;
    }
    for(int i = 2; i <= len2; i++) {
        dp1[0][i] = dp1[0][i-1] - b;
    }
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            dp1[i][j] = max(dp1[i][j - 1] - b , max(dp2[i][j - 1] , dp3[i][j - 1]) - a);
            dp2[i][j] = max(dp2[i - 1][j] - b , max(dp1[i - 1][j] , dp3[i - 1][j]) - a);
            dp3[i][j] = max(dp3[i - 1][j - 1] , max(dp2[i - 1][j - 1] , dp1[i - 1][j - 1])) + d[get(s1[i])][get(s2[j])];
        }
    }
    ans = max(dp3[len1][len2] , max(dp2[len1][len2] , dp1[len1][len2]));
    printf("%d\n" , ans);
    return 0;
}
