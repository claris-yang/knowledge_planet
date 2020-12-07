//
// Created by yangtao on 20-11-10.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main() {
    int g = 3, b = 4;
    auto c = [](int x, int y) ->int{ return x + y ;};
    cout << c (g, b) << endl;
    if(1){
        auto d = [=, &b] () ->int { return g + b;};
        cout << d() << endl;
    }
    return 0;
}