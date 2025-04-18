
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
         int n = bloomDay.size();
int a=-1;
        // if (m * k > n) {
        //     return -1;
        // }

         int s = *min_element(bloomDay.begin(), bloomDay.end());  
         int e = *max_element(bloomDay.begin(), bloomDay.end());  

        // for (int i = s; i <= e; i++) {
             int cnt = 0, nc = 0;   
            
        //     for (int j = 0; j < n; j++) {
        //         if (bloomDay[j] <= i) {
        //             cnt++;   
        //             if (cnt == k) {
        //                 nc++;   
        //                 cnt = 0;   
        //             }
        //         } else {
        //             cnt = 0;   
        //         }
        //     }
        //    if (nc >= m) {
        //         return i;
        //     }
        // }

        // return -1; 


while (s <= e) {
    int mid = s + (e - s) / 2;
    cnt = 0;
    nc = 0;

    for (int j = 0; j < n; j++) {
        if (bloomDay[j] <= mid) {
            cnt++;
            if (cnt == k) {
                nc++;
                cnt = 0;
            }
        } else {
            cnt = 0;
        }
    }

    if (nc >= m) {
        a = mid;
        e = mid - 1;
    } else {
        s = mid + 1;
    }
}


return a;


    }
};



 