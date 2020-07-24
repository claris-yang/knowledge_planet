//
// Created by yangtao on 19-10-12.
//

#include <iostream>

using namespace std;
char m[1005];
char k[105];
char c[1005];
int main() {

    cin >> k >> c;
    int i = 0, j = 0, l=0, n = 0;
    while( k[i] != 0 ) {
        if(k[i] >= 'A' && k[i] <= 'Z') {
            k[i] += 'a' - 'A';
        }
        i++;
        l++;
    }

    i = 0;
    while(c[j] != '\0') {
        m[j] = c[j] - (k[i % l] - 'a');
        if( c[j] >= 'A' && c[j] <= 'Z' && m[j] < 'A' ) {
            m[j] += 26;
        }
        if( c[j] >= 'a' && c[j] <= 'z' && m[j] < 'a' ) {
            m[j] += 26;
        }
        i++; j++;
    }
    cout << m;
    return 0;
}