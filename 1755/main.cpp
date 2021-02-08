//
// Created by munaiyi on 2021/1/31.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minAbsDifference(vector<int> &nums, int goal) {
        int n = nums.size();
        vector<int> dp(1 << 20 + 2, 0), dp2(1 << 20 + 2, 0);
        unordered_map<int, int> mp;
        for (int i = 0; i < min(n, 20); i++) {
            mp[1 << i] = nums[i];
        }
        for (int i = 1; i < (1 << min(20, n)); i++) {
            dp[i] = dp[i & (i - 1)] + mp[i - (i & (i - 1))];
        }
        sort(dp.begin(), dp.begin() + (1 << min(20, n)), [](int x, int y) { return x < y; });
        reverse(nums.begin(), nums.end());
        for (int i = 0; i < min(n, 20); i++) {
            mp[1 << i] = nums[i];
        }
        int ans = abs(goal);
        for (int i = 0; i < (1 << max(0, n - 20)); i++) {
            dp2[i] = dp2[i & (i - 1)] + mp[i - (i & (i - 1))];
            int now = goal - dp2[i];
            if (dp[0] > now) {
                ans = min(ans, abs(now - dp[0]));
            } else {
                int l = 0, r = (1 << min(20, n)) - 1;
                int t = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (dp[mid] <= goal) {
                        t = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                ans = min(ans, abs(now - dp[t]));
                if (t + 1 < (1 << min(20, n))) {
                    ans = min(ans, abs(now - dp[t + 1]));
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> shit{7, -9, 15, -2};
    cout << Solution().minAbsDifference(shit, -5);
}