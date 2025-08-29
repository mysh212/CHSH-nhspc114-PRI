#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inv6 = 166666668, MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    n %= MOD;
    cout << (n * (n - 1) % MOD * (4 * n + 1) % MOD * inv6 % MOD + n) % MOD << '\n';
}