class Solution:
    def helper(self, l, l1):
        for i in range(len(l)):
            l2 = l[:i] + l[i+1:]

            if l2 not in l1:
                l1.append(l2)
                self.helper(l2, l1)
                
        return l1

    def subsets(self, nums: list[int]) -> list[list[int]]:
        if not nums:
            return [[]]
        else:
            l1 = [nums] 
            
            return self.helper(nums, l1)