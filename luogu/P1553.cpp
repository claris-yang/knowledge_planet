//
// Created by yangtao on 19-7-23.
//

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string resv(string s) {

    reverse(s.begin(),s.end());

    return s;
}

string trimZero(string s) {
    int i = 0;
    for(i = 0 ; i < s.length() - 1; i++) {
        if(s[i] != '0' ){
            break;
        }
    }
    return s.substr(i);
}
int main() {
    string s;
    int pos ;
    cin >> s;
    if(s.find(".") != string::npos) {
        pos = s.find(".");
        string a  = trimZero(resv(s.substr(0, pos)));
        cout << a << "." << resv(trimZero(s.substr(pos+1)));
    } else if(s.find("/") != string::npos) {
        pos = s.find("/");
        cout << trimZero(resv(s.substr(0, pos)));
        cout << "/";
        cout << trimZero(resv(s.substr(pos+1)));
    } else if (s.find("%" )!= string::npos) {
        pos = s.find("%");
        cout << trimZero(resv(s.substr(0,pos))) << "%";
    } else {
        cout << trimZero(resv(s));

    }
    return 0;
}