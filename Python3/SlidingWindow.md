## Sliding Window
### Table of contents
1. [Best Time to Buy and Sell stocks](#max_profit)

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
