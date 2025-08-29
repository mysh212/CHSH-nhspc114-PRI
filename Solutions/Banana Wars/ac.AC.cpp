#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi bit;
void update(int x, int delta) {
    for (; x < sz(bit); x += x&-x) {
        bit[x] += delta;
    }
}
int get_sum(int x) {
    int sum = 0;
    for (; x > 0; x -= x & -x) {
        sum += bit[x];
    }
    return sum;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    map<pii, int> pnt_id;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        pnt_id[{x, y}] = i;
    }
    int m;
    cin >> m;
    vector<pii> lines;
    for (int i = 1; i <= m; ++i) {
        int sx, sy, px, py;
        cin >> sx >> sy >> px >> py;
        int id_1 = pnt_id[{sx, sy}], id_2 = pnt_id[{px, py}];
        if (id_1 > id_2) swap(id_1, id_2);
        lines.emplace_back(id_1, id_2);
    }
    sort(all(lines));
    ll ans = 0;
    bit.resize(n + 1);
    for (auto [x, y] : lines) {
        ans += get_sum(y) - get_sum(x - 1);
        update(y, 1);
    }
    cout << ans << '\n';
}