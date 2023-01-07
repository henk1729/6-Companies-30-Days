## 396. Rotate Function

1. This can be solved in O(n) time.
2. Calculate F(0).
3. If F(i) is known F(i+1) (by anticlockwise rotation) can be calculated by F(i+1) = F(i) - totSum + n * nums[i].
4. Compare currSum and maxSum. Return maxSum.
