class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        int i = 0;
        string word;

        while (iss >> word) {
            if (i == pattern.size()) return false;
            
            char c = pattern[i];


            if ((charToWord.count(c) && charToWord[c] != word) ||
                (wordToChar.count(word) && wordToChar[word] != c)) {
                return false;
            }


            charToWord[c] = word;
            wordToChar[word] = c;

            ++i;
        }

        return i == pattern.size();
    }
};