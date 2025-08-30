#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int L = 63;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<vector<ll>> bucket(L);
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        bucket[__lg(x)].emplace_back(x);
    }
    ll ans = 0;
    for (int i = L - 1; i >= 0; --i) {
        while (sz(bucket[i]) > 1) {
            ll num = bucket[i][0] ^ bucket[i].back();
            bucket[i].pop_back();
            if (num) {
                bucket[__lg(num)].emplace_back(num);
            }
        }
        if (!bucket[i].empty()) {
            ans = max(ans, ans ^ bucket[i][0]);
        }
    }
    cout << ans << '\n';
}

