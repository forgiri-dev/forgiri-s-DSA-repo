class Solution {
public:
    bool possible(const vector<int>& day, int m, int k, int d){
        int k1 = 0;
        int c1 = 0;
        
        for(int j{}; j < day.size(); j++){
            if(c1 == k){
                k1 += 1;
                c1 = 0;
            }
            
            if (day[j] - d > 0){
                c1 = 0;
            }
            if (day[j] - d <= 0){
                c1 += 1;
            }
        }
        
        if (c1 == k) {
            k1 += 1;
        }

        return (k1 >= m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;

        int h = *max_element(bloomDay.begin(), bloomDay.end());
        int l = 1;
        int mid = l + (h-l)/2;
        int ans = -1;
        
        while (l<=h){
            mid = l + (h-l)/2;
            if(possible(bloomDay, m, k, mid)){
                ans = mid;
                h = mid -1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};