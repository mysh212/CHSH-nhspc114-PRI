n = int(input())
MOD = 10**9 + 7
print(( n * (n - 1) * (4 * n + 1) * pow(6, -1, MOD) + n ) % MOD)
