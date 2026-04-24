class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        # Sort is required so we can easily skip duplicates
        candidates.sort()
        
        # We can define results here so the helper can access it directly
        results = []

        def helper(index, curr_sum, temp):
            if curr_sum == target:
                results.append(temp[:])
                return
            
            if curr_sum > target or index == len(candidates):
                return

            temp.append(candidates[index])
            helper(index + 1, curr_sum + candidates[index], temp)
            temp.pop()


            next_index = index + 1
            while next_index < len(candidates) and candidates[next_index] == candidates[index]:
                next_index += 1
            
            helper(next_index, curr_sum, temp)

        helper(0, 0, [])
        
        return results