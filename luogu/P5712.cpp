//
// Created by yangtao on 20-4-21.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int main() {
    cin >> n;
    if (n <= 1)
        printf("Today, I ate %d apple.", n);
    else {
        printf("Today, I ate %d apples.", n);
    }
    return 0;
}