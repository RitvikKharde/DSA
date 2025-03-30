class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        bool foundWord = false; 
        for (int i = n - 1; i >= 0; i--) {
             if (s[i] != ' ') {
                count++;
                foundWord = true; 
            }
            else if (foundWord) {
                break; 
            }
        }
        return count;
    }
};
