class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        int count = 1, maxCount = 0, maxElem = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                count = 1; 
            }

            if (count > maxCount) {
                maxCount = count;
                maxElem = nums[i];
            }
        }
        return maxElem;      
    }
};