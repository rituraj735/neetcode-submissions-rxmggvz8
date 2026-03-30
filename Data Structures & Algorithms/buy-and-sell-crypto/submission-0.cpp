class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = INT_MIN; 
        int _min = INT_MAX;
        int n = prices.size();
        for(int i =0; i<n; i++){
            profit= max(profit, prices[i] - _min);
            _min = min(prices[i], _min);
        }
        if(profit <= 0) return 0;
        else return profit;
    }
};
