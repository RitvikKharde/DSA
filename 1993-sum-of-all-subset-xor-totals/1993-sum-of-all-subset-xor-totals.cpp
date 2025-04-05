class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalOr = 0;
        for (int num : nums) {
            totalOr |= num;
        }
        return totalOr * (1 << (nums.size() - 1));
    }
};
