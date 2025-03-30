class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0; 
        int realpeak = -1; 
        for (int i = 0; i < n; i++) {
if ((i == 0 || nums[i-1] < nums[i]) && (i == n-1 || nums[i] > nums[i+1])) {
                
                realpeak = i;
                break; 
            }
        }
        return realpeak;

    }
};