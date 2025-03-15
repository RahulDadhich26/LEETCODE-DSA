class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        coins.sort()
        
        prev = [0]*(amount + 1)

        for i in reversed(range(len(coins))):
            cur = [0]*(amount+1)
            cur[0] = 1
            for j in range(1, amount+1):
                if j-coins[i] >=0:
                    cur[j] = prev[j] + cur[j-coins[i]]
                else:
                    cur[j] = prev[j]
                
            prev = cur
        
        return prev[amount]