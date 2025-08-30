from collections import defaultdict

def main():
  A, B, C, D, E, F, M = map(int, input().split())

  S = defaultdict(int)
  for i in range(1, M + 1):
    for j in range(1, M + 1):
      for k in range(1, M + 1):
        S[A * i + B * j + C * k] += 1

  ANS = 0
  for i in range(1, M + 1):
    for j in range(1, M + 1):
      for k in range(1, M + 1):
        V = D * i + E * j + F * k
        if -V in S:
          ANS += S[-V]

  print(ANS)

if __name__ == "__main__":
  main()