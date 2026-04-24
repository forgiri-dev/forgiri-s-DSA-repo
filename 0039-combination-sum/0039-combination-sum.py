class Solution:
    def helper(self, c, target, start_index, results, temp, curr_sum):
        
        if curr_sum == target:
            results.append(temp[:])
            return
        
        if curr_sum > target or start_index == len(c):
            return

        temp.append(c[start_index])
        
        self.helper(c, target, start_index, results, temp, curr_sum + c[start_index])
        
        temp.pop()
        
        self.helper(c, target, start_index + 1, results, temp, curr_sum) 

    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        results = []
        
        self.helper(candidates, target, 0, results, [], 0)
        
        return results