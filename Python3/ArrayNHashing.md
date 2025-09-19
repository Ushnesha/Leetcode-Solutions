## Array and Hashing
### Table of contents
1. [Contains Duplicate](#duplicate)
2. [Valid Anagram](#anagram)
3. [Two Sum](#2sum)

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

---
### Valid Anagram <a name="anagram"></a>
##### Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Input: s = "anagram", t = "nagaram" \
Output: true
```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # if sorted(s) == sorted(t):
        #     return True
        # else:
        #     return False


        # using hash table
        hmap = dict()
        if len(s) != len(t):
            return False
        for i in s:
            if i not in hmap:
                hmap[i] = 1
            else:
                hmap[i] = hmap[i] + 1
        
        for j in t:
            if j not in hmap:
                return False
            hmap[j] = hmap[j] - 1
    

        for key in hmap:
            if hmap[key] != 0:
                return False

        return True
```

---
### Two Sum <a name="anagram"></a>
##### Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.
Input: nums = [2,7,11,15], target = 9 \
Output: [0,1]
```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sum_comp = dict()
        for i in range(0,len(nums)):
            if nums[i] in sum_comp:
                return [sum_comp[nums[i]], i]
            else:
                sum_comp[target-nums[i]] = i
```


