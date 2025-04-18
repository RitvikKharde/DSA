//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++




//Brute Force Solution (Time limit exceeded)
// class Solution {
// public: 
//     bool CanWePlace(vector<int>& stalls, int dist, int cows) {
//         int count = 1;               
//         int lastPos = stalls[0];      
//         for (int i = 1; i < stalls.size(); i++) {
//             if (stalls[i] - lastPos >= dist) {
//                 count++;
//                 lastPos = stalls[i];
//             }
//             if (count == cows) return true;
//         }

//         return false;
//     }

//     int aggressiveCows(vector<int>& stalls, int k) {
//         sort(stalls.begin(), stalls.end());  

//         int n = stalls.size();
//         int maxDistance = stalls[n - 1] - stalls[0];  
//         int result = 0;

//         for (int dist = 1; dist <= maxDistance; dist++) {
//             if (CanWePlace(stalls, dist, k)) {
//                 result = dist;   
//             }
//         }

//         return result;  
//     }
// };


class Solution {
  public:
     bool CanWePlace(vector<int>& stalls, int dist, int cows) {
        int count = 1;
        int lastPos = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= dist) {
                count++;
                lastPos = stalls[i];
            }
            if (count == cows) return true;
        }

        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int s = 1;
        int e = stalls.back() - stalls.front();  
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (CanWePlace(stalls, mid, k)) {
                ans = mid;      
                s = mid + 1;    
            } else {
                e = mid - 1;   
            }
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends