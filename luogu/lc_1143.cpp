//
// Created by yangtao on 19-11-11.
//

#include <iostream>
using namespace std;
const int N = 1005;
int dp[N][N];
int longestCommonSubsequence(string text1, string text2) {
    if(text1.length() == 0 || text2.length() == 0) return 0;
    for(int i = 1  ;i <= text1.length(); i++) {
        for(int j = 1; j <= text2.length(); j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[text1.length()][text2.length()];
}
int main() {
    string text1 = "abc", text2 = "adbef";
    cout << longestCommonSubsequence(text1, text2);
    return 0;
}