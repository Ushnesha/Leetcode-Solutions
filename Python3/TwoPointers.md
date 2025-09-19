## Two Pointers
### Table of contents
1. [3Sum](#3sum)
2. [Container With Most Water](#most_water)
3. [Trapping Rain Water](#trap_water)
4. [Two Sum II - Input Array Is Sorted](#2sum_2)
5. [Valid Palindrome](#valid_palindrome)

---
### Container With Most Water <a name="most_water"></a>
##### You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a container, such that the container contains the most water.  Return the maximum amount of water a container can store.
<img width="801" height="383" alt="image" src="https://github.com/user-attachments/assets/c24061dc-e152-46ec-a2b8-4d73c59fae0a" />

Input: height = [1,8,6,2,5,4,8,3,7] \
Output: 49

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxA,j,i = 0,len(height)-1,0

        while(i<j):
            if height[i] < height[j]:
                maxA = max(maxA, (height[i]*(j-i)))
                i+=1
            else:
                maxA = max(maxA, (height[j]*(j-i)))
                j-=1
        
        return maxA
```

---
### Trapping Rain Water <a name="trap_water"></a>
##### Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
<img width="412" height="161" alt="image" src="https://github.com/user-attachments/assets/28f91b15-10f8-4d04-9f1b-42f3de1f7465" />

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]\
Output: 6
```python
class Solution:
    def trap(self, height: List[int]) -> int:
        maxL, maxR = 0, 0
        l,r = 0, len(height)-1 
        sumTot = 0
        while( l < r ):
            if height[l] < height[r]:
                sumTot += max(maxL-height[l], 0)
                maxL = max(maxL,height[l])
                l += 1
            else:
                sumTot += max(maxR-height[r], 0)
                maxR = max(maxR, height[r])
                r -= 1

        return sumTot
```

---
### 3Sum <a name="3sum"></a>
##### Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0. Notice that the solution set must not contain duplicate triplets.
Input: nums = [-1,0,1,2,-1,-4] \
Output: [[-1,-1,2],[-1,0,1]]
```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []

        for i, num in enumerate(nums):
            if i > 0 and num == nums[i-1]:
                continue
            
            j = i + 1
            k = len(nums) - 1
            while(j < k):
                if nums[i] + nums[j] + nums[k] > 0:
                    k -= 1
                elif nums[i] + nums[j] + nums[k] < 0:
                    j += 1
                else:
                    res.append([nums[i],nums[j],nums[k]])
                    j += 1
                    while(nums[j] == nums[j-1] and j < k):
                        j += 1
                
        return res
        
```

---
### Two Sum II - Input Array Is Sorted <a name="2sum_2"></a>
##### Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length. Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2. The tests are generated such that there is exactly one solution. You may not use the same element twice. Your solution must use only constant extra space.
Input: numbers = [2,7,11,15], target = 9 \
Output: [1,2]
```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i , j = 0 , len(numbers)-1
        while ( i < j ):
            sum_ = numbers[i] + numbers[j]
            if sum_ == target:
                return [i+1, j+1]
            elif sum_ > target:
                j = j - 1
            else:
                i = i + 1
        return [-1,-1]
```

---
### Valid Palindrome <a name="valid_palindrome"></a>
##### A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers. Given a string s, return true if it is a palindrome, or false otherwise.
Input: s = "A man, a plan, a canal: Panama" \
Output: true
```python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s_ = ""
        for ch in s:
            if ch.isalnum():
                s_ = s_ + ch.lower()
        i , j = 0 , len(s_) - 1
        while i < len(s_)/2:
            if s_[i] != s_[j]:
                return False
            i = i + 1
            j = j - 1
        return True

        
```
