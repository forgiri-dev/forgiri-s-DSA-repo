class Solution:
    def combinationSum3(self, k: int, n: int) -> list[list[int]]:
        t = k * (k + 1) // 2 
        
        if t > n or n > 45: 
            return []
            
        results = []
        temp = [] 
        
        def helper(num, current_sum):
            if len(temp) == k and current_sum == n:
                results.append(list(temp)) 
                return
            
            if len(temp) > k or current_sum > n:
                return
                
            for i in range(num, 10):
                temp.append(i)                
                helper(i + 1, current_sum + i)  
                temp.pop()                      
                
        helper(1, 0)
        
        return results