class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> result; 
        int count = 1; 
        result.push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                count = 1;
            }

             if (count <= 2) {
                result.push_back(nums[i]);
            }
        }

        nums = result;

        return result.size();
    }
};
