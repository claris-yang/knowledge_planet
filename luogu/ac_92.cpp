//
// Created by yangtao on 20-6-8.
//

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 20;
vector<int> v;
int n;
void dfs(int x) {
    if( x == n + 1) {
        for(auto a : v){
            printf("%d ", a);
        }
        printf("\n");
        return ;
    }

    dfs(x + 1);
    v.push_back(x);
    dfs(x + 1);
    v.pop_back();
}

int main() {
    cin >> n;
    dfs(1);
    return 0;

}