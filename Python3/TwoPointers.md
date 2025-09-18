## Two Pointers
### Table of contents
1. [Container With Most Water](#most_water)

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
