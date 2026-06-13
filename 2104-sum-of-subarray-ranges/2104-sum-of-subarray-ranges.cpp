class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> dp1(n, 0); 
        vector<long long> dp2(n, 0); 
        
        stack<int> st1; 
        stack<int> st2; 
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            
            while(!st1.empty() && nums[st1.top()] <= nums[i]){
                st1.pop();
            }
            if(st1.empty()){
                dp1[i] = (long long)(i + 1) * nums[i]; 
            } else {
                int prev = st1.top();
                dp1[i] = dp1[prev] + (long long)(i - prev) * nums[i];
            }
            
            while(!st2.empty() && nums[st2.top()] >= nums[i]){
                st2.pop();
            }
            if(st2.empty()){
                dp2[i] = (long long)(i + 1) * nums[i];
            } else {
                int prev = st2.top();
                dp2[i] = dp2[prev] + (long long)(i - prev) * nums[i];
            }
            
            st1.push(i);
            st2.push(i);
            
            ans += (dp1[i] - dp2[i]);
        }   
        
        return ans;     
    }
};