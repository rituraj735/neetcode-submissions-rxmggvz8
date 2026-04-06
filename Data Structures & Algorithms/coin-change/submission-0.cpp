class Solution {
public:
    int dfs(vector<int> &coins, int amount, unordered_map<int,int> &dp){
        if(dp.count(amount)) return dp[amount];
        int res = 1e9;
        for(int coin: coins){
            if(amount - coin >=0){
                res = min(res, 1+dfs(coins, amount-coin, dp));
            }
        }
        dp[amount] = res;
        return res;
    }
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        int minCoins = dfs(coins, amount, dp);
        return (minCoins >= 1e9) ? -1: minCoins;
    }
};
