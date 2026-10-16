class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
                int n = coins.size();

        if(amount == 0){
            return 0;
        }
        if(n==1){
            if(amount%coins[0] == 0){
                return amount/coins[0];
            }else{return -1;}
        }
        vector<int> t(amount+1, 0);
        for(int i{}; i < n; i++){
            if(coins[i] <= amount){
            t[coins[i]] = 1;}
        }
        for(int i = 1; i < amount + 1; i++){
            int k = i/2;
            for(int j = 1; j < k+1; j++){
                if(t[i] == 0 && t[i-j] != 0 && t[j] != 0){
                    t[i] = t[i-j] + t[j];
                }else{
                    if(t[i-j] != 0 && t[j] != 0){
                    t[i] = min(t[i], t[i-j] + t[j]);}
                }





                }
            }
            if(t[amount] == 0){
                return -1;
            }else{
                return t[amount];
            }
        }
    
};