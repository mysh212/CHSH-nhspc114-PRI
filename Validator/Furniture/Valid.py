# Author : ysh
# 2025/08/25 Mon 20:11:30
n, m = [int(i) for i in input().split()]
assert(0 <= n <= 2 * (10 ** 5))
assert(0 <= m <= 10 ** 6)

if not m == 0:
    f = [[int(i) for i in input().split()] for _ in range(m)]
    assert(len([True for j in f if all([1 <= i <= n for i in j])]) == m)
    assert(len([True for i in f if len(i) == 2]))

v = [int(i) for i in input().split()]
assert(len(v) == n)
assert([i for i in v if 0 <= i <= 10 ** 9] == v)

quit()