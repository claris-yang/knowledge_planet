//
// Created by yangtao on 20-6-15.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

struct Node {
    int val, cnt;
    bool operator<(const Node & node) const {
        return cnt < node.cnt;
    }
};
vector<Node> nodes;
class Solution {
public:

    map<int, int> m;
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        for(int i = 0 ;i < arr.size(); i++) {
            if(m.find(arr[i]) != m.end()) {
                m[arr[i]]++;
            } else {
                m[arr[i]] = 1;
            }
        }

        for(map<int, int>::iterator it = m.begin() ; it != m.end(); it++ ) {
            nodes.push_back({it->first, it->second});
        }

        sort(nodes.begin(), nodes.end());

        int res = m.size();
        for(int i = 0 ; i < nodes.size(); i++) {
            if( nodes[i].cnt <= k ) {
                k -= nodes[i].cnt;
                res -= 1;
            } else {
                break;
            }
        }

        return res;

    }
};

int main() {
    return 0;
}