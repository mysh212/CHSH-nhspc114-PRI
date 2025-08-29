#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, ans = 0;
    cin >> n;
    for (ll i = 1; i < n; ++i) {
        ans += i * (2 * i + 1) % MOD;
        ans %= MOD;
    }
    ans = (ans + n) % MOD;
    cout << ans << '\n';
}