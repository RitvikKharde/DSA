class Solution {
public:
    
    long long totalHours(const vector<int>& piles, int k) {
        long long total = 0;
        for (int pile : piles) {
            total += (pile + k - 1LL) / k;  
            }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        long long low = 1, high = maxPile;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long hoursNeeded = totalHours(piles, mid);

            if (hoursNeeded <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)low;
    }
};