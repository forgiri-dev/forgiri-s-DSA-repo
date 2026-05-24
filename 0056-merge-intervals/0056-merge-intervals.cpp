class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> results;

        for (int i = 0; i < intervals.size(); i++) {
            
            if (results.empty() || intervals[i][0] > results.back()[1]) {
                results.push_back(intervals[i]);
            } 
            else {
                results.back()[1] = max(results.back()[1], intervals[i][1]);
            }
        }

        return results;
    }
};