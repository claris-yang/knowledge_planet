//
// Created by yangtao on 20-5-20.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
map<string, int> m;
map<string, int>::iterator it;
int n;
int o;
int main() {
    cin >> n;
    for(int i = 0 ;i < n; i++) {
        string name;
        int score;
        cin >> o;
        if(o == 1) {
            cin >> name >> score;
            m[name] = score;
            cout << "OK" << endl;
        } else if( o == 2) {
            cin >> name;
            it = m.find(name);
            if(it == m.end()) {
                cout << "Not found" << endl;
            } else {
                cout << it->second<<endl;
            }
        } else if( o == 3) {
            cin >> name;
            it = m.find(name);
            if(it != m.end()) {
                m.erase(name);
                cout << "Deleted successfully" << endl;
            } else {
                cout << "Not found" << endl;
            }

        } else if (o == 4) {
            cout << m.size() << endl;
        }
    }
    return 0;
}
