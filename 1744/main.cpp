//
// Created by munaiyi on 2021/1/31.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
        vector<bool> ans;
        vector<long long> sum;
        int n = candiesCount.size();
        sum.push_back(candiesCount[0]);
        for (int i = 1; i < n; i++) {
            sum.push_back(sum.back() + candiesCount[i]);
        }
        for (auto &q:queries) {
            int type = q[0];
            int day = q[1] + 1;
            int cap = q[2];
            if (day > sum[type]) {
                ans.push_back(false);
                continue;
            }
            if (type && 1LL * cap * day <= sum[type - 1]) {
                ans.push_back(false);
                continue;
            }
            ans.push_back(true);
        }
        return ans;
    }
};

int main() {
    vector<int> candiesCount = {7, 4, 5, 3, 8};
    vector<vector<int>> queries = {{0, 2,  2},
                                   {4, 2,  4},
                                   {2, 13, 1000000000}};
    vector<bool> ans = Solution().canEat(candiesCount, queries);
    for (auto a:ans) {
        cout << a << endl;
    }

}