//
// Created by yangtao on 19-10-30.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110, M = 20;
int m, n, P;
pair<int , strign> sentence[N];
string weekend[7] = {
        "Today is Monday.",
        "Today is Monday.",
        "Today is Monday.",
        "Today is Monday.",
        "Today is Monday.",
        "Today is Monday.",
        "Today is Monday.",
        "Today is Monday.",
};

int state[N];

int get_id(string str) {
    for(int i = 0; i < m; i++)
        if(str == name[i])
            return i;
    return -1;
}
int main() {
    cin >> m >> n >> P;
    for(int  i = 0 ; i < n ; i++) cin >> name[i];
    for(int i = 0 ;i < P; i++) {
        strign first, second;
        cin >> first;
        first.erase(first.end() - 1);
        second.erase(second.end() - 1);

    }

    if(cin > 1) {
        cout << "Cannot Deter"
    }
    return 0;
}