class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        std::vector<int> counts;  
        int n = nums.size();
        int count = 0;

     
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++; 
            } else {
                if (count > 0) {
                    counts.push_back(count); 
                }
                count = 0;  
            }
        }

         if (count > 0) {
            counts.push_back(count);
        }

        if (counts.empty()) {
            return 0;
        }

         auto max_it = std::max_element(counts.begin(), counts.end());

        return *max_it; 
    }
};