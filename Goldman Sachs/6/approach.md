## 2260. Minimum Consecutive Cards to Pick Up

1. Make a map storing [card value: latest index] pairs in the vector.
2. Store 1-based indices (as default value in map will be `0`).
3. Keep taking minimum of answer required (which is initialised to `cards.size()+1`) and current value for index differences i.e. `((i+1)-cardPosition[cards[i]])+1`.
4. If the answer changes than what was initialised, return answer, else return `-1`.
