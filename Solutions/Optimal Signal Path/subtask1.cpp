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
    int base;
    cin >> base;
    vector<ll> dist(n + 1, INF);
    dist[base] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, base});
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

    int q;
    cin >> q;
    while (q--) {
        int s, t;
        cin >> s >> t;
        cout << dist[s] << '\n';
    }
}