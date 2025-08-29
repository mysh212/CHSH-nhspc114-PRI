#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int &x : nums) {
        cin >> x;
    }

    multiset<int> small, large;
    double mid = 1e9;
    for (int l = 0, r = 0; r < n; r++) {
        if (nums[r] >= *large.begin()) {
            large.insert(nums[r]);
        } else {
            small.insert(nums[r]);
        }

        if (r >= k) {
            if (nums[l] >= *large.begin()) {
                large.erase(large.find(nums[l]));
            } else {
                small.erase(small.find(nums[l]));
            }
            l++;
        }

        if (small.size() > k / 2 && large.size() < (k + 1) / 2) {
            large.insert(*small.rbegin());
            small.erase(prev(small.end()));
        }
        if (small.size() < k / 2 && large.size() > (k + 1) / 2) {
            small.insert(*large.begin());
            large.erase(large.begin());
        }

        if (r - l + 1 >= k && k & 1) {
            mid = min((double)*large.begin(), mid);
        } else if (r - l + 1 >= k) {
            mid = min((*small.rbegin() + *large.begin()) / 2.00, mid);
        }
    }

    cout << fixed << setprecision(10) << k * mid << '\n';
}