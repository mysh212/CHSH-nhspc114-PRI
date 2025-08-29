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
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        adj[0].emplace_back(x, 0);
    }

    vector<ll> dist(n + 1, INF);
    dist[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({d + w, v});
            }
        }
    }

    vector<char> vis;
    auto dfs = [&](auto self, int u, int target, ll neck) -> bool {
        if (dist[u] > neck || vis[u]) {
            return false;
        }
        if (u == target) {
            return true;
        }
        vis[u] = true;
        for (auto [v, w] : adj[u]) {
            if (self(self, v, target, neck)) {
                return true;
            }
        }
        return false;
    };

    int q;
    cin >> q;
    while (q--) {
        int s, t;
        cin >> s >> t;

        ll l = 0, r = INF;
        while (l <= r) {
            ll mid = (l + r) / 2;
            vis.assign(n + 1, 0);
            if (dfs(dfs, s, t, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << l << '\n';
    }
}