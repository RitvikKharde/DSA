class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftmax(n), rightmax(n);
         
        leftmax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }

        rightmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i + 1], height[i]);
        }
 
        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            int currentWater = min(leftmax[i], rightmax[i]) - height[i];
            if (currentWater > 0) {
                totalWater += currentWater;
            }
        }

        return totalWater;
    }
};




// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if (n == 0) return 0;
//         int totalwater = 0;
         
//         for(int i=0;i<n;i++){
//             int leftmax=0, rightmax=0;
//         for(int j=0;j<=i;j++){
//             leftmax=max(leftmax,height[j]);
//         }
//         for(int j=i;j<n;j++){
//             rightmax=max(rightmax,height[j]);
//         }
//         int currentwater=min(leftmax,rightmax)-height[i];
//         if(currentwater>0){
//             totalwater+=currentwater;
//         }
//         }

//         return totalwater;
//     }
// };
