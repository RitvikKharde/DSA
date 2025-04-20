class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        int totalRabbits = 0;

        for (int answer : answers) {
            freq[answer]++;
        }

        for (auto& entry : freq ) {
            int x = entry.first;    
            int count = entry.second;

            int groupSize = x + 1;
            int groupsNeeded = (count + x) / groupSize; 
            totalRabbits += groupsNeeded * groupSize;
        }

        return totalRabbits;
    }
};
