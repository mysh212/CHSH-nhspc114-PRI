#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

constexpr ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pll>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int k;
    cin >> k;
    vector<ll> dist(n + 1, INF);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        dist[x] = 0;
    }

    auto dfs1 = [&](auto self, int u, int par) -> void {
        for (auto [v, w] : adj[u]) {
            if (v == par) continue;
            self(self, v, u);
            dist[u] = min(dist[v] + w, dist[u]);
        }
    };
    dfs1(dfs1, 1, 0);

    auto dfs2 = [&](auto self, int u, int par) -> void {
        for (auto [v, w] : adj[u]) {
            if (v == par) continue;
            dist[v] = min(dist[u] + w, dist[v]);
            self(self, v, u);
        }
    };
    dfs2(dfs2, 1, 0);

    dist[0] = 0;

    const int lgn = __lg(n);
    vector<int> depth(n + 1);
    vector<vector<ll>> jump(n + 1, vector<ll>(lgn + 1)), mx_w(n + 1, vector<ll>(lgn + 1));
    auto build = [&](auto self, int u, int par) -> void {
        depth[u] = depth[par] + 1;
        jump[u][0] = par;
        mx_w[u][0] = max(dist[par], dist[u]);
        for (int j = 1; j <= lgn; ++j) {
            int mid = jump[u][j - 1];
            jump[u][j] = jump[mid][j - 1];
            mx_w[u][j] = max(mx_w[mid][j - 1], mx_w[u][j - 1]);
        }
        for (auto [v, _] : adj[u]) {
            if (v == par) continue;
            self(self, v, u);
        }
    };
    build(build, 1, 0);

    auto find_neck = [&](int u, int v) -> ll {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        ll neck = 0;
        int diff = depth[u] - depth[v];
        for (int j = 0; diff; j++, diff>>=1) {
            if (diff & 1) {
                neck = max(neck, mx_w[u][j]);
                u = jump[u][j];
            }
        }
        if (u == v) {
            return neck;
        }
        for (int j = lgn; j >= 0; j--) {
            if (jump[u][j] != jump[v][j]) {
                neck = max(neck, max(mx_w[u][j], mx_w[v][j]));
                u = jump[u][j];
                v = jump[v][j];
            }
        }
        return max(neck, max(mx_w[u][0], mx_w[v][0]));
    };

    int q;
    cin >> q;
    while (q--) {
        int s, t;
        cin >> s >> t;
        if (s == t) {
            cout << dist[s] << '\n';
        } else {
            cout << find_neck(s, t) << '\n';
        }
    }
}