class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), greater<int>());
        
        int h = 0; 
        
        for (int i = 0; i < n; i++) {
            if (citations[i] >= h + 1) {
                h++;  
                 } else {
                break;  
                  }
        }
        return h;
    }
};