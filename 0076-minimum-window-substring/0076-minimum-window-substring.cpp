using namespace std;
class Solution {
private:
    bool required(const unordered_map<char, int>& h, unordered_map<char, int>& h1){
        for(const auto& [key, value] : h){
            if(h1[key] < value){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> h;
        for(int i = 0; i < t.size(); i++){
            h[t[i]] += 1; 
        }
        
        int min_len = INT_MAX; 
        int start_idx = 0;
        int l = 0;
        int r = 0;
        unordered_map<char,int> h1;
        while (r < s.size()) {
            h1[s[r]]++;
            while (required(h, h1)) {                
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start_idx = l;
                }
                h1[s[l]]--;
                l++;
            }
            r++;
        }
        if (min_len == INT_MAX) {
            return "";
        }
        return s.substr(start_idx, min_len);
    }
};