//
// Created by munaiyi on 2021/1/31.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
        vector<int> ans;
        
    }
};

int main() {
    vector<vector<int>> adjacentPairs = {{2, 1},
                                   {3, 4},
                                   {3, 2}};
    vector<int> ans = Solution().restoreArray(adjacentPairs);
    for (auto a:ans) {
        cout << a << endl;
    }

}