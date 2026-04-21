
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool possible(const vector<int>& p, int h, int m) {
        long long count = 0; 
        
        for (int i = 0; i < p.size(); i++) {
            count += (p[i] + m - 1) / m; 
        }

        return (count <= h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 0;
        
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(piles, h, mid)) {
                k = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }

        return k;
    }
};