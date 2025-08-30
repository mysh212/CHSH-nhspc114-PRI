#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct  Node {
    Node *child[2] = {nullptr, nullptr};
};

constexpr int L = 62;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<ll> pre(n + 1);
    Node *root = new Node();
    for (int i = 0; i <= n; ++i) {
        if (i) {
            ll a;
            cin >> a;
            pre[i] = pre[i - 1] ^ a;
        }
        Node *node = root;
        for (int j = L; j >= 0 ; --j) {
            int bit = (pre[i]>>j) & 1;
            if (!node->child[bit]) {
                node->child[bit] = new Node();
            }
            node = node->child[bit];
        }
    }
    
    ll ans = 0;
    for (ll x : pre) {
        Node *node = root;
        ll cur_xor = 0;
        for (int i = L; i >= 0; --i) {
            int bit = (x>>i) & 1;
            if (node->child[bit ^ 1]) {
                cur_xor |= 1LL<<i;
                node = node->child[bit ^ 1];
            } else {
                node = node->child[bit];
            }
        } 
        ans = max(ans, cur_xor);
    }
    cout << ans << '\n';
}

