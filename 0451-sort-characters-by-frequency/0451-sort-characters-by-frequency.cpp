
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }
        
        vector<pair<char, int>> freqVector(freqMap.begin(), freqMap.end());
        
        sort(freqVector.begin(), freqVector.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; 
        });
        
        string result = "";
        result.reserve(s.size());   
        
        for (const auto& pair : freqVector) {
            result.append(pair.second, pair.first);
        }
        
        return result;
    }
};