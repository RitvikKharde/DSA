class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return nums[0];
        }
        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            if (nums[i]<mini){
                mini=nums[i];
            }

        }
        return mini;



    }
};