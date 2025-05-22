// //Brute force
// class Solution {
// public:
//     int maxDepth(string s) {
//         int cnt = 0;      
//         int maxc = 0;     
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '(') {
//                 cnt++;
//                 maxc = max(maxc, cnt);  
//             } else if (s[i] == ')') {
//                 cnt--;
//             }
//         }

//         return maxc;
//     }
// };



// Using stack
class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk;
        int maxDepth = 0;

        for (char ch : s) {
            if (ch == '(') {
                stk.push(ch);
                maxDepth = max(maxDepth, (int)stk.size()); 
            } else if (ch == ')') {
                if (!stk.empty()) {
                    stk.pop(); 
                }
            }
        }

        return maxDepth;
    }
};
