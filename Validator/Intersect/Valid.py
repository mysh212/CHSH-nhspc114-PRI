# Author : ysh
# 2025/08/02 Sat 17:53:54
n = int(input())
assert(1 <= n <= 2 * (10 ** 5))

f = [int(i) for i in input().split()]
assert(len(f) == n)
assert([i for i in f if 1 <= i <= 10 ** 18] == f)

quit()