#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int max_sum = 0;
        
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        
        max_sum = lsum;
        
        int right_index = cardPoints.size() - 1;
        
        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];
            
            rsum += cardPoints[right_index];
            right_index--;
            
            max_sum = max(max_sum, lsum + rsum);
        }
        
        return max_sum;
    }
};