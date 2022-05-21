#include "std.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //可重复使用。完全背包。dp[i][j] 前i个硬币凑出金额j时的最少硬币数。
        vector<vector<int>> dp(n + 1, vector<int>(amount+1,amount+1));
        //初始化  dp[i][0] 凑出金额为0所需最小个数均为0个。
        for(int i = 0; i < n+1; ++i){
            dp[i][0] = 0;
        }

        //外层循环遍历物品,内层循环遍历背包。
        for (int i = 1; i < n+1; ++i){
            for (int j = 0; j < amount+1; ++j){
                if (j >= coins[i-1]){
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);//完全背包时dp[i][j-coins[i-1]]这种情况(参考背包九讲), 因为每种物品可选无限件,所以在考虑"加选一件第i种物品时"这种策略时，却正需要一个可能已选入第i种物品的子结果dp[i][j-coins[i-1]]。而01背包中时dp[i-1][j-coins[i-1]]是为了保证每件物品只选一次，保证在考虑"选入第i件物品"这个策略时，依据的是一个绝无已选入第i件物品的子结果dp[i-1][j-coins[i-1]]。
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        //确认返回值
        return dp[n][amount] == amount+1?-1:dp[n][amount];

    }

    int coinChange(vector<int>& coins, int amount) {
        //硬币可以重复无限次使用，所以是完全背包问题。
        //dp[j] 表示凑出金额j时的最小硬币数量。
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        
        for (int i = 0; i < coins.size(); ++i){
            for (int j = 1; j < amount + 1; ++j){
                if (j < coins[i]) {
                }else{
                    dp[j] = min(dp[j], dp[j-coins[i]] + 1);
                }
            }
        }
        return dp[amount] == amount+1?-1:dp[amount];
    }
};

