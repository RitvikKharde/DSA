//time limit exceed- not optimal
// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, long long k) {
//         int n = nums.size();
//         for (int i = 0; i < n - 1; i++) {
//             long long prefix = nums[i];
//             for (int j = i + 1; j < n; j++) {
//                 prefix += nums[j];
//                 if (k == 0) {
//                     if (prefix == 0) return true;
//                 } else {
//                     if (prefix % k == 0) return true;
//                 }
//             }
//         }
//         return false;
//     }
// };



//Optimal solution
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modIndex;
        modIndex[0] = -1;  

        int prefixSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];

            if (k != 0)
                prefixSum %= k;

            if (modIndex.find(prefixSum) != modIndex.end()) {
                if (i - modIndex[prefixSum] >= 2)
                    return true;
            } else {
                modIndex[prefixSum] = i;  
            }
        }

        return false;
    }
};

