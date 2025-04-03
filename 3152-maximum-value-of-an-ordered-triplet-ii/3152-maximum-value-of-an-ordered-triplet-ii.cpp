class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; 
        int maxPrefix = nums[0];
        long long maxDiff = LLONG_MIN;
        long long result = 0;
        
        for (int j = 1; j < n - 1; j++) {
            maxDiff = max(maxDiff, (long long)maxPrefix - nums[j]);
            
            result = max(result, maxDiff * nums[j + 1]);
            
            maxPrefix = max(maxPrefix, nums[j]);
        }
        
        return result;
    }
};
