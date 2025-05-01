// class Solution {
// public:
//     int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int p, int strength) {
//         int n = tasks.size(), m = workers.size();
        
//         sort(tasks.begin(), tasks.end());
//         sort(workers.begin(), workers.end());
//         int lo = 0, hi = min(m, n);
//         int ans;
        
//         while(lo <= hi) {
//             int mid = lo + (hi - lo) / 2;
//             int count = 0;
//             bool flag = true;
            
//             multiset<int> st(workers.begin(), workers.end());
            
//             for(int i = mid - 1; i >= 0; i--) {
                
//                 auto it = prev(st.end());
//                 if(tasks[i] <= *it) {
                    
//                     st.erase(it);
//                 } else {
                    
//                     auto it = st.lower_bound(tasks[i] - strength);
//                     if(it != st.end()) {
                        
//                         count++;
//                         st.erase(it);
//                     } else {
                        
//                         flag = false;
//                         break;
//                     }
//                 }
                
//                 if(count > p) {
//                     flag = false;
//                     break;
//                 }
//             }
            
//             if(flag) {
//                 ans = mid;
//                 lo = mid + 1;
//             } else {
//                 hi = mid - 1;
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    bool canPerform(int taskCount, const vector<int>& tasks, const vector<int>& workers, int pills, int boost) {
        multiset<int> pool(workers.end() - taskCount, workers.end());
        int usedPills = 0;

        for (int i = taskCount - 1; i >= 0; --i) {
            int required = tasks[i];
            auto strongest = pool.end();
            --strongest;

            if (*strongest >= required) {
                pool.erase(strongest);
            } else {
                if (usedPills >= pills) return false;

                auto withPill = pool.lower_bound(required - boost);
                if (withPill == pool.end()) return false;

                pool.erase(withPill);
                ++usedPills;
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0, high = min((int)tasks.size(), (int)workers.size());
        int maxTasks = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPerform(mid, tasks, workers, pills, strength)) {
                maxTasks = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return maxTasks;
    }
};

