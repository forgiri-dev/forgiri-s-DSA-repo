class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i{}; i < nums.size(); i++){
            int j = i+1;
            while(j < nums.size() && j <= i + k ){
                if(nums[i] == nums[j]){
                    return true;
                }else{
                    j++;
                }


            }
        }
        return false;
    }
};