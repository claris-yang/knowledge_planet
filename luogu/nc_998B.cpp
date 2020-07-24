//
// Created by yangtao on 20-5-28.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 20;
int n, m;
vector<int> a;
vector<vector<int> > b;
void dfs(int x) {
    if( a.size() > m || a.size() + n - x + 1 < m) return ;
    if(x == n + 1) {
        b.push_back(a);
        return;
    }
    dfs(x  + 1) ;
    a.push_back( x ) ;
    dfs(x + 1);
    a.pop_back();
}
int main() {
    cin >> n >> m;
    dfs(1);
    for(int i = b.size() - 1 ; i >= 0; i--)  {
        for(int j = 0 ; j < b[i].size(); j ++ ) {
            printf("%d ", b[i][j]);
        }
        cout << endl;
    }
    return 0;
}