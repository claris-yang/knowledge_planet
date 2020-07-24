//
// Created by yangtao on 20-5-9.
//

#include <iostream>
#include <cstring>
using namespace std;
const int N = 255;
char s[N];
int k;
int l;
int cnt ;
int main() {
    cin >> s >> k;
    l = strlen(s);
    cnt = l - k;
    for(int i = 0; i < l; i++) {
        if(k <= 0) break;
        for(int j = i + 1; j <= l; j++) {
            if( s[j] == 0 ) continue;
            if( s[i] >= s[j] ) {
                s[i] = 0;
                k--;
                break;
            }
        }
    }
    bool flag = true;
    for(int i = 0 ; i < l ; i++) {

        if( s[i] == '0' && flag || s[i] == 0 && flag) continue;
        flag = false;
        if(  s[i] != 0 && cnt > 0 ) {
            cout << s[i];
            cnt--;
        }

    }
    return 0;
}
