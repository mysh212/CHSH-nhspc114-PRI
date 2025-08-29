#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

constexpr ll INF = 1e18;

struct Edge {
    int u, v;
    ll w;
    Edge(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}
    bool operator<(const Edge &rh) {
        return w < rh.w;
    }
};

vector<int> dsu;
int Get(int x) {
    if (dsu[x] == x) {
        return x;
    }
    return dsu[x] = Get(dsu[x]);
}
void Merge(int x, int y) {
    x = Get(x), y = Get(y);
    dsu[x] = y;
}

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
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(d + w, v);
            }
        }
    }

    dsu.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        dsu[i] = i;
    }
    vector<Edge> edges;
    for (int u = 1; u <= n; ++u) {
        for (auto [v, w] : adj[u]) {
            edges.emplace_back(u, v, max(dist[u], dist[v]));
        }
    }
    vector<vector<pll>> tree(n + 1);
    sort(edges.begin(), edges.end());
    for (auto [u, v, w] : edges) {
        if (Get(u) != Get(v)) {
            Merge(u, v);
            tree[u].emplace_back(v, w);
            tree[v].emplace_back(u, w);
        }
    }

    const int lgn = __lg(n);
    vector<int> depth(n + 1);
    vector<vector<ll>> jump(n + 1, vector<ll>(lgn + 1)), mx_w(n + 1, vector<ll>(lgn + 1));
    auto dfs = [&](auto self, int u, int par, ll par_w) -> void {
        depth[u] = depth[par] + 1;
        jump[u][0] = par;
        mx_w[u][0] = par_w;
        for (int j = 1; j <= lgn; ++j) {
            int mid = jump[u][j - 1];
            jump[u][j] = jump[mid][j - 1];
            mx_w[u][j] = max(mx_w[mid][j - 1], mx_w[u][j - 1]);
        }
        for (auto [v, w] : tree[u]) {
            if (v == par) continue;
            self(self, v, u, w);
        }
    };
    dfs(dfs, 1, 0, 0);

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