#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using pii = pair<int, int>;
using ordered_set = tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int &x : nums) {
        cin >> x;
    }

    ordered_set ost;
    double mid = 1e9;
    for (int l = 0, r = 0; r < n; r++) {
        ost.insert({nums[r], r});
        if (r >= k) {
            ost.erase({nums[l], l});
            l++;
        }
        if (r - l + 1 >= k) {
            mid = min((ost.find_by_order(k / 2)->first + ost.find_by_order((k - 1) / 2)->first) / 2.00, mid);
        }
    }
    cout << fixed << setprecision(10) << k * mid << '\n';
}