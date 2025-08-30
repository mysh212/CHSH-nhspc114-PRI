# Author : ysh
# 2025/08/13 Wed 11:27:36
R = 10 ** 9 + 7

n = int(input())
n %= R

sig = n * (n + 1) * ((n << 1) + 1) // 6 - n
up = n ** 3

print((up - sig) % R)
quit()