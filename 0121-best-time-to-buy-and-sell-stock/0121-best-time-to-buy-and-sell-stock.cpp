class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0; 
        
        int buy = prices[0];
        
        int maxProfit = 0;  
        
        for (int i = 1; i < n; i++) {
           int profit = prices[i] - buy;

            maxProfit = std::max(maxProfit, profit);

            buy = std::min(buy, prices[i]);
        }

        return maxProfit; 
    }
};
