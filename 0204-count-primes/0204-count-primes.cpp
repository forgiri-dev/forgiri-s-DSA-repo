class Solution{
    public:
    int countPrimes(int n) {

    if (n <= 2) return 0;
    
    int numOdds = (n - 3) / 2 + 1;
    if (numOdds <= 0) return 1; 

    std::vector<int> compositeBitset((numOdds + 31) / 32, 0);

    int count = 1;

    for (long long i = 3; i < n; i += 2) {
        int idx = (i - 3) / 2;
        int word = idx >> 5;       
        int bit = idx & 31;        

        if (!(compositeBitset[word] & (1 << bit))) {
            count++;

            for (long long j = i * i; j < n; j += 2 * i) {
                int compositeIdx = (j - 3) / 2;
                compositeBitset[compositeIdx >> 5] |= (1 << (compositeIdx & 31));
            }
        }
    }

    return count;
}
};