//
// Created by yangtao on 19-11-1.
//

#include <iostream>
using namespace std;
int n;
int half;
int main() {
    cin >> n;
    half = n / 2 + 1;
    for(int i = 1;i <=n; i++ ) {
        for(int j = 1; j <=n; j++) {
            if(i == 1 || j == half)
                cout << "*";
            else
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}