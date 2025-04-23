class Solution {
public:
    int countLargestGroup(int n) {
        int map[40] = {0};
        int maxGroup = 0, ans = 0;

        for (int i = 1; i <= n; ++i) {
            int sum = 0, num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            map[sum]++;
            if (map[sum] > maxGroup) {
                maxGroup = map[sum];
                ans = 1;
            } else if (map[sum] == maxGroup) {
                ans++;
            }
        }

        return ans;
    }
};