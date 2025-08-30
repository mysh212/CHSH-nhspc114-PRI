#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;

struct chash { // large odd number for C
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c, d, e, f, m;
    cin >> a >> b >> c >> d >> e >> f >> m;

    gp_hash_table<ll, ll, chash> cnt;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                cnt[a*i + b*j + c*k]++;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                ll tmp = d*i + e*j + f*k;
                if (cnt.find(-tmp) != cnt.end()) {
                    ans += cnt[-tmp];
                }
            }
        }
    }
    cout << ans << '\n';
}