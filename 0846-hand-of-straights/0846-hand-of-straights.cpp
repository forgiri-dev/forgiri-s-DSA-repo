class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        
        unordered_map<int, int> count;
        for(int card : hand) {
            count[card]++;
        }
        
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(auto& pair : count) {
            minheap.push(pair.first);
        }
        
        while(!minheap.empty()){
            int first = minheap.top();
            
            if(count[first] == 0) {
                minheap.pop();
                continue;
            }
            
            for(int i = 0; i < groupSize; i++){
                int currentCard = first + i;
                
                if(count[currentCard] == 0) {
                    return false; 
                }
                
                count[currentCard]--;
            }
        }
        
        return true;
    }
};