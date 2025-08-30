# Author : ysh
# 2025/08/01 Fri 23:50:33
# https://www.luogu.com.cn/problem/P3812
import sys

input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
f = [int(i) for i in input().split()]

R = 64
mark = [0 for _ in range(R)]
for i in f:
    for j in range(R - 1, -1, -1):
        if i == 0:
            break
        if not (i & (1 << j)):
            continue
        if mark[j] == 0:
            mark[j] = i
            break
        else:
            i ^= mark[j]

ans = 0
for i in range(R - 1, -1, -1):
    if ans & (1 << i):
        continue
    ans = max(ans, ans ^ mark[i])

print(f'{ans}')