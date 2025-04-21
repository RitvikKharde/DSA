//Brute Force
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n=nums.size();
//         if(n==0){
//             return -1;
//         }

//         for(int i=0;i<n;i++){
//             if (target==nums[i]){
//                 return i;
//             }
//         }
//         return -1;      
//     }
// };


//Binary Search- Optimal
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int m;

        while(s<=e){
            m=s+(e-s)/2;

            if(nums[m]==target){
                return m;
            }

           else if(nums[0]<=nums[m]){           //Checking the direction of sorting
                if(nums[s]<=target && target<=nums[m]){
                    e=m-1;
                }
                else{
                    s=m+1;
                }
            }
            else{
                if(nums[m]<=target && target<=nums[e]){
                    s=m+1;
                }
                else{
                    e=m-1;                }
            }
        }
        return -1;
    }
};