//
// Created by yangtao on 20-4-30.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int N = 60;
int n, n1, n2;
char s;
char c;
char c1[N], c2[N];
char t[N];
int main() {
    cin >> n;
    for(int i = 0 ;i < n; i++) {
        cin >> c ;
        memset(t, 0, sizeof(t));
        if(c != 'a' && c != 'b' && c != 'c') {
            memset(c1, 0, sizeof(c1));
            memset(c2, 0, sizeof(c2));
            c1[0] = c;
            cin >> c1 + 1 >> c2;
            n1 = atoi(c1);
            n2 = atoi(c2);
        } else {
            cin >> n1 >> n2;
            s = c;
        }


        if(s == 'a') {
            sprintf(t, "%d+%d=%d", n1, n2, n1 + n2);
        } else if (s == 'b') {
            sprintf(t, "%d-%d=%d", n1, n2, n1 - n2);
        } else {
            sprintf(t, "%d*%d=%d", n1, n2, n1 * n2);
        }

        cout << t << endl;
        cout << strlen(t) << endl;
    }
    return 0;
}
