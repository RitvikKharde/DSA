//Brute force method
// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int missingCount = 0;
//         int current = 0;
//         int i = 0;
        
//         while (missingCount < k) {
//             current++; 
//             if (i < arr.size() && arr[i] == current) {

//                 i++;
//             } else {
//                 missingCount++;
//             }
//         }

//         return current; 
//     }
// };



//Optimal Solution- Binary Search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int missing = arr[mid] - (mid + 1);  //Total missing numbers till index mid, 

            if (missing < k) {
                left = mid + 1;  
            } else {
                right = mid - 1;  
            }
        }
 
        return left + k;
    }
};
