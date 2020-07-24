//
// Created by yangtao on 19-10-8.
//

#include <iostream>
#include <string>
using namespace std;
char str[2048];
void dfs(int s, int e) {

    int num = 0;
    for(int i = s; i <= e; i++) {
        if(str[i] == '1') {
            num++;
        }
    }

    char t = 'F';

    if(e - s + 1 == num) {
        t = 'I';
    } else if( num == 0 ) {
        t = 'B';
    }

    if(s == e) {
        cout << t ;
        return ;
    }

    int mid = (s + e) / 2 ;
    dfs(s, mid);
    dfs(mid + 1, e);

    cout << t ;
}
int main() {
    int n;
    cin >> n >> str;
    dfs(0, (1 << n) -1);
    return 0;
}
