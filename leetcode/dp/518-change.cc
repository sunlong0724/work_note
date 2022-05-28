#include "std.h"

/* 此题可以和 377 对比来看
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //每种物品可以无限次使用，完全背包。dp[i][j] 表示前i种面额的硬币凑出金额j的组合数。
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1,0));
        //0种面额硬币凑出金额0的组合数是1。
        dp[0][0] = 1;

        //外层循环遍历物品，内层遍历背包容量
        for (int i = 1; i < coins.size()+1; ++i){
            for (int j = 0; j < amount+1;++j){
                if (j >= coins[i-1]){
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];//完全背包。不考虑coins[i-1]凑出金额j的组合数dp[i-1][j] + 考虑coins[i-1]凑出金额的组合数dp[i][j-coins[i-1]]。
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};