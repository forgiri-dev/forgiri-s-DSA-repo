class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size(), -1);
        for(int i{}; i < nums.size()*2; i++){
            int curr = nums[i%nums.size()];
            while(st.size()  != 0 && nums[st.top()] < curr){
                res[st.top()] = curr;
                st.pop();
            }

            if(i<nums.size()){
                st.push(i);
            }
        }
        return res;
    }
};