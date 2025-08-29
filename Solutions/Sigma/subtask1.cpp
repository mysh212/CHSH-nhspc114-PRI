#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, ans = 0;
    cin >> n;
    for (ll i = 1; i <= n * n; ++i) {
        ans += int(sqrt(i));
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
}