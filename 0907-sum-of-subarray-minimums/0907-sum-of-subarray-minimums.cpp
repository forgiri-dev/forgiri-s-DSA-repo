class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> left(n, -1);
        vector<int> right(n, n);
        
        stack<int> monoStack;
        
        for (int i = 0; i < n; ++i) {
            while (!monoStack.empty() && arr[monoStack.top()] >= arr[i]) {
                monoStack.pop();
            }
            if (!monoStack.empty()) {
                left[i] = monoStack.top();
            }
            monoStack.push(i);
        }
        
        monoStack = stack<int>();
        
        for (int i = n - 1; i >= 0; --i) {
            while (!monoStack.empty() && arr[monoStack.top()] > arr[i]) {
                monoStack.pop();
            }
            if (!monoStack.empty()) {
                right[i] = monoStack.top();
            }
            monoStack.push(i);
        }
        
        long long totalSum = 0;
        const int MOD = 1e9 + 7;
        
        for (int i = 0; i < n; ++i) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;
            
            long long contribution = (leftCount * rightCount % MOD) * arr[i] % MOD;
            totalSum = (totalSum + contribution) % MOD;
        }
        
        return totalSum;
    }
};