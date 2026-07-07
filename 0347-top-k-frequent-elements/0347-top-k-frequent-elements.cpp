class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result; 
        unordered_map<int, int> h;
        
        for (int num : nums) {
            h[num]++;
        }
        
        priority_queue<pair<int, int>> maxheap;
        for (const auto& it : h) {
            maxheap.push({it.second, it.first}); 
        }
        
        for (int i = 0; i < k; i++) {            
            result.push_back(maxheap.top().second);
            maxheap.pop();
        }
        
        return result;
    }
};