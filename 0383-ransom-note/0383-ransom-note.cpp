class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int h1[26]{};
        for(int i{}; i < magazine.size(); i++){
            h1[magazine[i] - 'a'] += 1;    
        }
        for(int j{}; j < ransomNote.size(); j++){
            if(h1[ransomNote[j] - 'a'] == 0){
                return false;
            }else{
                h1[ransomNote[j] - 'a'] -= 1;

            }

        }
        return true;

    }
};