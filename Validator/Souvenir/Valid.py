# Author : ysh
# 2025/08/29 Fri 00:43:29
n = int(input())
f = [[int(j) for j in input().split()] for _ in range(n)]

assert(0 <= n <= 2 * (10 ** 5))
assert(len(f) == n)
assert([i for i in f if len(i) == 2] == f)
assert([i for i in f if all([1 <= j <= 10 ** 9 for j in i])] == f)

quit()