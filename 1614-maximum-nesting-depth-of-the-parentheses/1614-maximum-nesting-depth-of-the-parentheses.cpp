class Solution {
public:
    int maxDepth(string s) {
        int maxnesting{};
        int currnesting{};
        for(int i{}; i < s.size(); i++){
            if(s[i] == '('){
                currnesting++;

            }
            else{
            maxnesting = max(maxnesting, currnesting);
            if(s[i] == ')'){
                currnesting--;
            }}


        }
        return maxnesting;
        
    }
};