class Solution {
public:
    char getChar(int step, int index) {
        if (step == 0) return 'a';
        
        int half = 1 << (step - 1);
        
        if (index < half) {
            return getChar(step - 1, index);
        } else {
            char ch = getChar(step - 1, index - half);
            return (ch == 'z') ? 'a' : ch + 1;
        }
    }
    
    char kthCharacter(int k) {
        int step = 0;
        while ((1 << step) < k) {
            step++;
        }
        return getChar(step, k - 1);
    }
};
