class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long res = 0;
        int left = 0;
        long long pairs = 0;

        for (int right = 0; right < n; ++right) {
            pairs += freq[nums[right]];
            freq[nums[right]]++;

            while (pairs >= k) {
                res += (n - right);
                pairs -= (freq[nums[left]] - 1);
                freq[nums[left]]--;
                left++;
            }
        }

        return res;
    }
};
