class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> parenMap = {
            {'(', ')'}, {'{', '}'}, {'[', ']'}, {'<', '>'}
        };
        
        stack<char> stk;
        
        for (char c : s) {
            if (parenMap.count(c)) {
                stk.push(c);
            } 
            else {
                if (stk.empty()) return false;
                
                char top = stk.top();
                stk.pop();
                
                if (parenMap[top] != c) {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};