## Array and Hashing
### Table of contents
1. [Contains Duplicate](#duplicate)

---
### Contains Duplicate <a name="duplicate"></a>
##### Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
Input: nums = [1,2,3,1] \
Output: true
```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        for i in range(0, len(nums)-1):
            if nums[i] == nums[i+1]:
                return True
            
        return False
```
