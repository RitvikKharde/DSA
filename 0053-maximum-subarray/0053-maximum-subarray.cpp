class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0; 
        int currentMax = nums[0];
        int globalMax = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            currentMax = max(nums[i], currentMax + nums[i]);
            if (currentMax > globalMax) {
                globalMax = currentMax;
            }
        }

        return globalMax;
    }
};
