#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    ll mx = 0;
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        ll a;
        cin >> a;
        pre[i] = pre[i - 1] ^ a;
        mx = max(pre[i], mx);
    }
    auto ck = [&pre](ll mask, ll target) -> bool {
        unordered_set<ll> used;
        for (ll x : pre) {
            if (used.count((x & mask) ^ target)) {
                return true;
            }
            used.insert(x & mask);
        }
        return false;
    };

    ll lg = __lg(mx), mask = 0, ans = 0;
    while (lg >= 0) {
        mask |= 1LL<<lg;
        if (ck(mask, ans | (1LL<<lg))) {
            ans |= 1LL<<lg; 
        }
        --lg;
    }
    cout << ans << '\n';
}

