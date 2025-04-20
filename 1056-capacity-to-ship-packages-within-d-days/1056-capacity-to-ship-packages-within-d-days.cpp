class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int e = accumulate(weights.begin(), weights.end(), 0);
        int s = *max_element(weights.begin(), weights.end());


        int ans = e;

        while (s <= e) {
            int m = s + (e - s) / 2;

            int cnt = 1;
            int tw = 0;

            for (int i = 0; i < n; i++) {
                if (tw + weights[i] > m) {
                    cnt++;
                    tw = 0;
                }
                tw += weights[i];
            }

            if (cnt <= days) {
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }

        return ans;
    }
};
