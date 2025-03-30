class Solution {
public:
    int singleNumber(vector<int>& nums) {
        

        int n=nums.size();

        if(n==1){
            return nums[0];
        } 
        for (int i = 0; i < n; i++) {
            bool isUnique = true; 
            for (int j = 0; j < n; j++) {
                if (i != j && nums[i] == nums[j]) { 
                    isUnique = false;
                    break; 
                }
            }

            if (isUnique) {
                return nums[i]; 
            }
        }
        return -1;
    }
};