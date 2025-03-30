class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;){
            if (nums[i]==0){
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                n--;
            }
            else i++;

        }


        
    }
};