#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ori(ll a, ll b, ll c, ll d) {
    ll det = a * d - b * c;
    if (det == 0) {
        return 0;
    }
    return det > 0 ? -1 : 1;
}
bool intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    int o1 = ori(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
    int o2 = ori(x2 - x1, y2 - y1, x4 - x1, y4 - y1);
    int o3 = ori(x4 - x3, y4 - y3, x1 - x3, y1 - y3);
    int o4 = ori(x4 - x3, y4 - y3, x2 - x3, y2 - y3);
    if (o1 != o2 && o3 != o4) {
        return true;
    }
 
    if (!o1 && !o2 && !o3 && !o4 && !(max(x1, x2) < min(x3, x4) || max(x3, x4) < min(x1, x2)) && !(max(y1, y2) < min(y3, y4) || max(y3, y4) < min(y1, y2))) {
        return true;
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
    }

    int m;
    cin >> m;
    vector<int> lx1(m), ly1(m), lx2(m), ly2(m);
    for (int i = 0; i < m; i++) {
        cin >> lx1[i] >> ly1[i] >> lx2[i] >> ly2[i];
    }

    ll ans = 0;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (intersect(lx1[i], ly1[i], lx2[i], ly2[i], lx1[j], ly1[j], lx2[j], ly2[j])) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}