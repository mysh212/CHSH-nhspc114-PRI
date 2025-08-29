#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr i64 inf = (i64) 5e18;
constexpr int MAXN = 2005;

int N, K;
i64 A[MAXN], S[MAXN], Q[MAXN];
i64 dpPrev[MAXN], dpCur[MAXN];

// calc(i, j) = (sum)^2 - L * sumSq
inline i64 calc(int i, int j) {
  const i64 sum   = S[j] - S[i - 1];
  const i64 sumSq = Q[j] - Q[i - 1];
  const i64 L     = j - i + 1;
  return sum * sum - L * sumSq;
}

void solveLayer(int jL, int jR, int optL, int optR) {
  if (jL > jR) return;
  int jMid = (jL + jR) >> 1;

  i64 bestVal = -inf;
  int bestPos = optL;
  int up = min(jMid, optR);
  for (int i = optL; i <= up; ++i) {
    if (dpPrev[i - 1] == -inf) continue;
    i64 cand = dpPrev[i - 1] + calc(i, jMid);
    if (cand > bestVal) {
      bestVal = cand;
      bestPos = i;
    }
  }
  dpCur[jMid] = bestVal;

  solveLayer(jL, jMid - 1, optL, bestPos);
  solveLayer(jMid + 1, jR, bestPos, optR);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  for (int i = 1; i <= N; ++i) cin >> A[i];

  S[0] = 0;
  Q[0] = 0;
  for (int i = 1; i <= N; ++i) {
    S[i] = S[i - 1] + A[i];
    Q[i] = Q[i - 1] + A[i] * 1LL * A[i];
  }

  for (int j = 0; j <= N; ++j) dpPrev[j] = -inf, dpCur[j] = -inf;
  dpPrev[0] = 0;

  i64 answer = -inf;
  int KK = min(K, N);

  for (int k = 1; k <= KK; ++k) {
    for (int j = 0; j < k; ++j) dpCur[j] = -inf;
    solveLayer(k, N, k, N);

    answer = max(answer, dpCur[N]);

    for (int j = 0; j <= N; ++j) {
      dpPrev[j] = dpCur[j];
      dpCur[j] = -inf;
    }
  }

  cout << answer << '\n';
  return 0;
}
