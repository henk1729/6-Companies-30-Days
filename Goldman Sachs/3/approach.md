## 172. Factorial Trailing Zeroes

1. No. of trailing zeroes can be given by power of `10` or `5` in the prime factorization of `n`.
2. For power of `5`, we need to find the no. of numbers in `n!` which are divisible by `5`, then by `25`(since in `n!` where `n >= 25`, there will be additional powers of `5`) and so on.
3. Hence, divide `n` by powers of `5` while `n` is still larger than the powers and keep on adding them.
