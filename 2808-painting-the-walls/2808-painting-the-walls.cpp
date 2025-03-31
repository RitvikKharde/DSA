class Solution {
public:
    int dp[501][501]; \
    int solve(vector<int>& cost, vector<int>& time, int i, int remaining) {
        if (remaining <= 0) return 0;  
        if (i >= cost.size()) return 1e9; 
        
        if (dp[i][remaining] != -1) return dp[i][remaining];


        int take = cost[i] + solve(cost, time, i + 1, remaining - 1 - time[i]);


        int skip = solve(cost, time, i + 1, remaining);

        return dp[i][remaining] = min(take, skip);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof(dp));
        return solve(cost, time, 0, cost.size());
    }
};
