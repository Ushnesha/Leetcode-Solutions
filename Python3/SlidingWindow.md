## Sliding Window
### Table of contents
1. [Best Time to Buy and Sell stocks](#max_profit)
2. [Longest Substring Without Repeating Characters](#max_len_no_repeat)

---
### Best Time to Buy and Sell stocks <a name="max_profit"></a>
##### You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Input: prices = [7,2,1,5,3,6,4] \
Output: 5
```python
# one-pass solution
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice , maxProfit = float("inf") , 0
        for i in range(len(prices)):
            if prices[i] < minPrice:
                minPrice = prices[i]
            elif prices[i] - minPrice > maxProfit:
                maxProfit = prices[i] - minPrice
        return maxProfit

```

---
### Longest Substring Without Repeating Characters <a name="max_len_no_repeat"></a>
##### Given a string s, find the length of the longest substring without duplicate characters.
Input: s = "pwwkewmno" \
Output: 6
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLen = 0
        if len(s) > 0:
            i , j = 0, 1
            hashMap = {}
            hashMap[s[i]] = 0
            while(j<len(s)):
                if s[j] in hashMap and hashMap[s[j]] >= i:
                    maxLen = max(maxLen, j-i)
                    i = hashMap[s[j]] + 1
                hashMap[s[j]] = j
                j += 1
            maxLen = max(maxLen, j-i)
        return maxLen
```
