#include "std.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 == 1){
            return false;
        }

        int target = sum /2;

        //dp[i]  是否存在和为i的子集
        vector<bool> dp(target+1, false);
        dp[0] = true;

        for (int i = 0; i < nums.size(); ++i){
            for (int j = target; j >= 0; --j){
                if (j >= nums[i]){
                    dp[j] = dp[j] || dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1){
            return false;
        }
        int target = sum /2;
        //不能重复使用。01背包。
        //dp[i][j] 前i个数是否能凑出和为j。dp定义要考虑为空集的情况。
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(target+1, false));
        dp[0][0] = true;

        for (int i = 1; i < nums.size()+1; ++i){
            for (int j = 0; j < target+1; ++j){
                if (j >= nums[i-1]){
                    dp[i][j] = dp[i-1][j]||dp[i-1][j-nums[i-1]];//dp[i][j] 应该为不考虑nums[i-1]时是否凑出金额j 或 考虑nums[i-1]时凑出金额j 两种情况。
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][target];

    }
};