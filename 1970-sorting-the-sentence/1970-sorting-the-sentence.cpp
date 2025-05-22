class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10); 
        stringstream ss(s);
        string word;
        
        while (ss >> word) {
            int pos = word.back() - '0';   
            word.pop_back();               
            words[pos] = word;             
        }
        
        string result = words[1];
        for (int i = 2; i < words.size() && !words[i].empty(); i++) {
            result += " " + words[i];
        }
        
        return result;
    }
};
