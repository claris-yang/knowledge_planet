//
// Created by yangtao on 20-5-28.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 20;
vector<int> a;
int n;

void dfs(int x) {
    if(x == n + 1 ) {
        for(int i = 0 ; i < a.size(); i++) {
            printf("%d ", a[i]);
        }
        cout << endl;
        return;
    }
    dfs(x + 1);
    a.push_back(x);
    dfs(x + 1);
    a.pop_back();
}
int main() {
    cin >> n;
    dfs(1);
    return 0;
}