#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>; 

struct Edge {
    int u, v;
    ll w;
    bool operator<(const Edge &rh) {
        return w < rh.w;
    }
};
struct UF {
    vi e;
    UF(int n) : e(n + 1, -1) {};
    int find(int x) {
        return e[x] < 0 ? x : e[x] = find(e[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

constexpr ll INF = 1e18;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
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

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> dist(n + 1, INF);
    dist[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (auto [v, w] : adj[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.emplace(d + w, v);
            }
        }
    }
    vector<Edge> edges;
    for (int u = 1; u <= n; ++u) {
        for (auto [v, w] : adj[u]) {
            edges.emplace_back(u, v, max(dist[u], dist[v]));
        }
    }
    sort(all(edges));

    int q;
    cin >> q;
    vi S(q), T(q), q_ids;
    vector<ll> L(q, 0), R(q, INF);
    for (int i = 0; i < q; ++i) {
        cin >> S[i] >> T[i];
        if (S[i] != T[i]) q_ids.push_back(i);
    }
    vector<pll> check;
    do {
        int ei = 0;
        UF uf(n);
        check.clear();
        for (int i : q_ids) {
            if (L[i] <= R[i]) {
                ll mid = (L[i] + R[i]) / 2;
                check.emplace_back(mid, i);
            }
        }
        sort(all(check));
        q_ids.clear();
        for (const auto &[mid, id] : check) { 
            for (; ei < sz(edges) && edges[ei].w <= mid; ++ei) {
                uf.unite(edges[ei].u, edges[ei].v);
            }
            if (uf.find(S[id]) == uf.find(T[id])) {
                R[id] = mid - 1;
            } else {
                L[id] = mid + 1;
            }
            q_ids.push_back(id);
        }
    } while (!q_ids.empty());

    for (int i = 0; i < q; ++i) {
        if (S[i] == T[i]) {
            cout << dist[S[i]] << '\n';
        } else {
            cout << L[i] << '\n';
        }
    }
}