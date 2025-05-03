class Solution {
public:
    int check(vector<int>& A, vector<int>& B, int target) {
        int swapA = 0, swapB = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != target && B[i] != target) {
                return -1;  
            } else if (A[i] != target) {
                swapA++;  
            } else if (B[i] != target) {
                swapB++; }
        }
        return std::min(swapA, swapB);
    }

    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int res = check(A, B, A[0]);
        if (res != -1 || A[0] == B[0]) return res;
        return check(A, B, B[0]);
    }
};
