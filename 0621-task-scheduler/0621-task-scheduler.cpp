#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        int max_freq = 0;
        
        for (char task : tasks) {
            counts[task - 'A']++;
            max_freq = max(max_freq, counts[task - 'A']);
        }
        
        int num_max_tasks = 0;
        for (int count : counts) {
            if (count == max_freq) {
                num_max_tasks++;
            }
        }
        
        int required_length = (max_freq - 1) * (n + 1) + num_max_tasks;
        
        return max((int)tasks.size(), required_length);
    }
};