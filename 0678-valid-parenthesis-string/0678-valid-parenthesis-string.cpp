
class Solution {
public:
    bool checkValidString(std::string s) {
        std::stack<int> openStack;
        std::stack<int> starStack;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                openStack.push(i);
            } else if (s[i] == '*') {
                starStack.push(i);
            } else { 
                if (!openStack.empty()) {
                    openStack.pop(); 
                } else if (!starStack.empty()) {
                    starStack.pop(); 
                } else {
                    return false;    
                }
            }
        }
        
        while (!openStack.empty() && !starStack.empty()) {
            if (openStack.top() < starStack.top()) {
                openStack.pop();
                starStack.pop();
            } else {
                break;
            }
        }
        
        return openStack.empty();
    }
};