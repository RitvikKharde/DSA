 class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

         for (int num : nums) {
            if (num == el1) {
                cnt1++;
            } else if (num == el2) {
                cnt2++;
            } else if (cnt1 == 0) {
                el1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                el2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

         cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (num == el1) cnt1++;
            if (num == el2) cnt2++;
        }

        int mini = nums.size() / 3;
        vector<int> result;
        if (cnt1 > mini) result.push_back(el1);
        if (cnt2 > mini && el1 != el2) result.push_back(el2);

        return result;
    }
};
