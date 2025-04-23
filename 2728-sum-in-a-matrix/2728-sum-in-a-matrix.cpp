class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int row = nums.size();
        int col = nums[0].size();
        int score = 0;

         for (int i = 0; i < row; ++i) {
            sort(nums[i].begin(), nums[i].end());
        }

         for (int j = col - 1; j >= 0; --j) {
            int roundMax = 0;
            for (int i = 0; i < row; ++i) {
                roundMax = max(roundMax, nums[i][j]);
            }
            score += roundMax;
        }

        return score;
    }
};
