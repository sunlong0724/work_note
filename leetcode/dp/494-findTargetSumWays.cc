#include "std.h"

class Solution {
public:
    int findTargetSumWays0(vector<int>& nums, int target) {
        //sum(p)- sun(N) = target
        //sum(p) + sum(N) + sum(p)- sun(N) = target + sum(p)+sum(N)
        //2sum(p) = target + sum(nums)
        //sum(p) = (target + sum(nums))/2

        int sum = 0;
        sum = std::accumulate(nums.begin(), nums.end(), 0);
        if ((target+sum) % 2 == 1 || abs(target) > sum) {//target绝对值比sum还大??
            return 0;
        }
        target = (sum+target)/2;
        //dp[j]  结果等于i时的不同表达式数目。
        //1.当背包容量不能装下nums[i]时，dp[j]直接继承之前的dp[j]
        //2.当能装下nums[i]时，总的反感数为不考虑nums[i]时的方案数加上添加进nums[i]时的方案数。
        vector<int> dp(target + 1, 0);
        //初始化,空集是任一条有效路径的起点，当属于一条。
        dp[0] = 1;
        //外层循环遍历物品，内存循环遍历背包。物品不可重复使用，此乃01背包。
        for (int i = 0; i < nums.size(); ++i){
            for (int j = target; j >= nums[i]; --j){
                dp[j] += dp[j-nums[i]];
            }
        }

        return dp[target];
    }

     int findTargetSumWays(vector<int>& nums, int target) {
        //sum(p)- sun(N) = target
        //sum(p) + sum(N) + sum(p)- sun(N) = target + sum(p)+sum(N)
        //2sum(p) = target + sum(nums)
        //sum(p) = (target + sum(nums))/2

        int sum = 0;
        sum = std::accumulate(nums.begin(), nums.end(), 0);
        if ((target+sum) % 2 == 1 || abs(target) > sum) {//target绝对值比sum还大??
            return 0;
        }
        target = (sum+target)/2;

        vector<vector<int>> dp(nums.size()+1, vector<int>(target+1,0));
        dp[0][0] = 1;

        for (int i = 1; i <= nums.size(); ++i){
            for (int j = 0; j < target+1; ++j){
                if (j >= nums[i-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];/*到底是dp[i-1][j-nums[i-1]]还是dp[i][j-nums[i-1]]呢？该种情况是考虑nums[i-1]这个数，所以得是dp[i-1][j-nums[i-1]]。dp[i][j-nums[i-1]]表达的是考虑nums[i-1]时容量是j-nums[i-1]的方案数。 */
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][target];
     }
};