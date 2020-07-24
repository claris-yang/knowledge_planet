//
// Created by yangtao on 20-4-22.
//
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 5005;
char s1[N], s2[N], t[N];
int tmp[N];
int n;
int k;
void add() {
    cout << s1 <<  ' ' << s2 << endl;
    int len = max(strlen(s1), strlen(s2));

    k = 0;
    memset(tmp, 0, sizeof(tmp));
    for(; k < len ; k++) {
       tmp[k] = tmp[k] + (s1[k] - '0') + (s2[k] - '0');
       if(tmp[k] > 10) {
           tmp[k+1]++;
           tmp[k] -= 10;
       }
    }

    if(tmp[k] <= 0 ) k--;

    memset(t , 0, sizeof(t));
    for(int j = 0; j <= k; j++) {
        t[j] = tmp[j] + '0';
    }

    memset(s1, 0, sizeof(s1));
    strcpy(s1,  s2);
    memset(s2, 0, sizeof(s2));
    strcpy(s2,  t);

    cout << s2 << ' ' << k << ' ' << tmp[k] << ' ' << t <<  endl;

}
int main() {
    cin >> n;
    s1[0] = '1';
    s2[0] = '1';
    for(int i = 2; i <= n; i++) {
        add();
    }
    for(int i = k; i >= 0  ; i--) {
        printf("%c", s2[i]);
    }
    return 0;
}
