//
// Created by munaiyi on 2021/1/31.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkPartitioning(string s) {
        int l = s.length();
        vector<vector<bool>> dp(l, vector<bool>(l, false));
        for(int i=0;i<l;i++){
            dp[i][i] = true;
        }
        for(int i=1;i<l;i++){
            for(int j=0;j+i<l;j++){
                if(s[j]==s[j+i]){
                    dp[j][j+i] = dp[j+1][j+i-1]|(i==1);
                }
            }
        }
        for (int i = 0; i < l; i++) {
            if (dp[0][i]) {
                for (int j = i + 2; j < l; j++) {
                    if (dp[i + 1][j - 1] & dp[j][l - 1]) return true;
                }
            }

        }
        return false;
    }
};

int main() {
    cout << Solution().checkPartitioning({"abcbdd"});
}