class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi=INT_MIN;
        int fs=-1;
        int suffix;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,nums[i]);
            suffix=maxi-nums[i];
            if (suffix > 0) {
                fs = max(fs, suffix);   
            }
        }
        return fs;
    }
};