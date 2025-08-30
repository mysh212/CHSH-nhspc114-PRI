#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c, d, e, f, m;
    cin >> a >> b >> c >> d >> e >> f >> m;

    unordered_map<ll, ll> cnt;
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
                ans += cnt[-(d*i + e*j + f*k)];
            }
        }
    }
    cout << ans << '\n';
}