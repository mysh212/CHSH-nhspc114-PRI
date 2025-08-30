#pragma GCC optimize("Ofast,unroll-loops")

#include <cstdio>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <limits>
#include <iostream>
#include <chrono>
#include <queue>
#include <random>
#include <functional>
#include <vector>
#include <bitset>
#include <ranges>

using namespace std;

#ifdef LOCAL
#include "debug"
#else
#define debug(...)
#endif

using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = int(1e9);
template <>
constexpr int64_t infty<int64_t> = int64_t(1e18);
template <>
constexpr __int128_t infty<__int128_t> = __int128_t(1e36);
template <>
constexpr double infty<double> = 1e30;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fi first
#define se second

template<class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, true : false);
}
template<class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, true : false);
}
template <size_t N>
struct DSU {
  int dsu[N];
  vector<tuple<int, int, int, int>> his;
  void init(const int n) {
    for (int i = 1; i <= n; i++) {
      dsu[i] = -1;
    }
    his.clear();
    his.reserve(3600000);
  }
  int Get(const int x) { 
    return (dsu[x] < 0 ? x : Get(dsu[x]));
  }
  int size(const int x) { 
    return -dsu[Get(x)]; 
  }
  bool same(int x, int y) { 
    return Get(x) == Get(y); 
  }
  bool Merge(int x, int y) {
    x = Get(x);
    y = Get(y);
    if (x != y) {
      if (dsu[x] < dsu[y]) {
        swap(x, y);
      }
      his.emplace_back(x, dsu[x], y, dsu[y]);
      dsu[y] += dsu[x];
      dsu[x] = y;
      return true;
    }
    return false;
  }
  int time() {
    return int(his.size());
  }
  void revert(const int t) {
    while (int(his.size()) > t) {
      auto [x, vx, y, vy] = his.back();
      his.pop_back();
      dsu[x] = vx;
      dsu[y] = vy;
    }
  }
};
constexpr usize maxn = 200005;
int N, M, K, Q, X[maxn];
int S[maxn], T[maxn];
i64 dis[maxn], ANS[maxn];
vector<array<i64, 3>> E;
vector<pair<int, int>> adj[maxn];
DSU<maxn> dsu;
void Dijkstra(int N, i64 *dis) {
  priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> h;
  for (int i = 1; i <= N; i++) {
    dis[i] = infty<i64>;
  }
  rep (i, 1, K) h.emplace(dis[X[i]] = 0, X[i]);
  while (not h.empty()) {
    const auto [d, x] = h.top();
    h.pop();
    if (dis[x] != d) {
      continue;
    }
    for (const auto &[y, w] : adj[x]) {
      if (dis[y] > d + w) {
        dis[y] = d + w;
        h.emplace(dis[y], y);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> M;
  rep (i, 1, M) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
    E.push_back({-1, u, v});
  }
  cin >> K;
  rep (i, 1, K) cin >> X[i];
  Dijkstra(N, dis);
  cin >> Q;
  rep (i, 1, Q) cin >> S[i] >> T[i];
  const auto dfs = [&](this auto &&self, int l, int r, auto &qry) -> void {
    if (l >= r) {
      return;
    }
    if (r - l == 1) {
      for (const int &i : qry) {
        ANS[i] = E[l][0];
      }
      return;
    }
    const int m = midpoint(l, r);
    const int t = dsu.time();
    rep (i, l, m - 1) dsu.Merge(E[i][1], E[i][2]);
    vector<int> qryL, qryR;
    for (const int &i : qry) {
      if (dsu.same(S[i], T[i])) {
        qryL.push_back(i);
      } else {
        qryR.push_back(i);
      }
    }
    vector<int>().swap(qry);
    self(m, r, qryR);
    dsu.revert(t);
    self(l, m, qryL);
  };
  vector<int> qry(Q);
  ranges::iota(qry, 1);
  dsu.init(N);
  for (auto &[w, u, v] : E) {
    w = max(dis[u], dis[v]);
  }
  ranges::sort(E);
  dfs(0, M, qry);
  rep (i, 1, Q) cout << (S[i] == T[i] ? dis[S[i]] : ANS[i]) << '\n';
  return 0;
}