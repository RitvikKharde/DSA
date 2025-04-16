class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long res = 0, pairs = 0;
        int left = 0;
        int n = nums.size();

        for (int right = 0; right < n; ++right) {
            pairs += freq[nums[right]];
            freq[nums[right]]++;

            while (pairs >= k) {
                res += (n - right);  
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }

        return res;
    }
};
