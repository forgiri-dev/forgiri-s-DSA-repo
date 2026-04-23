class Solution:
    def countGoodNumbers(self, n: int) -> int:
        MOD = 10**9 + 7
        

        ans = pow(20, n // 2, MOD)
        
        if n % 2 != 0:
            ans = (ans * 5) % MOD
            
        return ans