class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x, mid, ans = 0;

        if (x == 0 || x == 1)
            return x;

        while (start <= end) {
            mid = start + (end - start) / 2;

            long long square = (long long)mid * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};
