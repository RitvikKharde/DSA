class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==target){
                result.push_back(i);
                break;
            }
        }
        for(int j=n-1;j>=0;j--){
            if(nums[j]==target){
                result.push_back(j);
                break;
            }
        }
        if (result.size() < 2) {
            return {-1, -1};
        }
        return result;
    }
};