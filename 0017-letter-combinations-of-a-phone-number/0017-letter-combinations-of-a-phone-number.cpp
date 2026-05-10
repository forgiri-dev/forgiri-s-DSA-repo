class Solution {
private:
    vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(const string& digits, int index, string current_combo, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current_combo);
            return;
        }

        int digit = digits[index] - '0';
        string letters = pad[digit];

        for (char letter : letters) {
            backtrack(digits, index + 1, current_combo + letter, result);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        if (digits.empty()) {
            return result;
        }

        backtrack(digits, 0, "", result);

        return result;
    }
};