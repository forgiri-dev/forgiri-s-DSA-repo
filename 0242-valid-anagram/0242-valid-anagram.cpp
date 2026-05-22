class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size() ){
            return false;
        }
        int has1[260]{};
        for(int i{}; i < t.size(); i++){
            has1[t[i]] += 1;


        }
        for(int j{}; j < s.size(); j++){
            if (has1[s[j]] == 0){
                return false;
            }else{
                has1[s[j]] -= 1;

            }
        }
        return true;
    }
};