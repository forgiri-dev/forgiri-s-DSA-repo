class KthLargest {
private:
    int k_limit;
    priority_queue<int, vector<int>, greater<int>> minheap;

public:
    KthLargest(int k, vector<int>& nums) {
        k_limit = k; 
        for(int i = 0; i < nums.size(); i++){
            minheap.push(nums[i]);
            
            if(minheap.size() > k_limit){
                minheap.pop();
            }
        }
    }
    
    int add(int val) {
        minheap.push(val);
        
        
        if(minheap.size() > k_limit){
            minheap.pop(); 
        }
        
        return minheap.top(); 
    }
};