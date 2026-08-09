class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dicte ={}
        for i,num in enumerate(nums):
            diff = target - num
            if diff in dicte:
                return [i,dicte[diff]]
            
            dicte[num] = i
        return None
            


