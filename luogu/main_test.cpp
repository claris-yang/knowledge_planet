//
// Created by yangtao on 19-8-12.
//

#include <iostream>
using namespace std;
int test() {
    int a ;
    return a = 10;
}
int main() {
    cout << test() << endl;
    return 0;
}