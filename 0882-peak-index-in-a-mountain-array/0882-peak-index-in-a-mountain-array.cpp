class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int m;
        int e=arr.size()-1;


        while(s<=e){
m=e+(s-e)/2;

if(arr[m]>arr[m-1] && arr[m]>arr[m+1]){
    return m;
}
else if( arr[m]>arr[m-1]){
    s=m+1;
}
else{
    e=m-1;
}

        }
        return -1;
        
    }
};




//Solution-2
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int s = 0;
//         int e = arr.size() - 1;
        
//         while (s < e) {
//             int m = s + (e - s) / 2;
            
//             if (arr[m] > arr[m + 1]) {
//                 e = m;
//             } else {
//                 s = m + 1;
//             }
//         }
        
//         return s;
//     }
// };
