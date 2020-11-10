//
// Created by yangtao on 20-10-23.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 30;
string str;
unordered_map<string, string> s;
int main() {
    int n;
    while( getline(cin , str) ) {
        int i = 0 ;
        string a, b;
        if(str == "") break;
        for(; i < str.length(); i++) {
            if(str[i] == ' ' ) break;
            a+=str[i];
        }
        i++;
        for(; i < str.length(); i++) {
            b+=str[i];
        }
        s[string(b)] = string(a);
    }

    string t;
    while(cin >> t) {
        if(s.find(t) != s.end()) {
            cout << s[t] << endl;
        } else {
            cout << "eh" << endl;
        }
    }
    return 0;
}
