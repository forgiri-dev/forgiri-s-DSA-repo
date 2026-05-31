class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = (digits[digits.size()-1] + 1)/10;
        digits[digits.size()-1] = (digits[digits.size()-1] + 1)%10;
        
        for(int i = digits.size()-2; i >= 0; i--){
            int current_sum = digits[i] + c; 
            digits[i] = current_sum % 10;
            c = current_sum / 10;           
        }
        
        if(c != 0){
            digits.insert(digits.begin(), c); 
        }
        return digits;
    }
};