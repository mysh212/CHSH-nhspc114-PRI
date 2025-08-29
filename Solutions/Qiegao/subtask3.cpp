#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ck(vector<ll> &nums, ll k, ll mid) {
    vector<ll> pre(nums.size() + 1);
    for (ll i = 1; i <= nums.size(); i++) {
        pre[i] += (nums[i - 1] <= mid) + pre[i - 1];
        if (i >= k && pre[i] - pre[i - k] > k / 2) {
            return true;
        }
    }
    return false;
}

ll median(vector<ll>& nums, ll k) {
    ll l = INT_MIN, r = INT_MAX;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (ck(nums, k, mid)) {
            r = mid - 1;
        } else {
            l =  mid + 1;
        }
    }
    return l;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (ll &x : nums) {
        cin >> x;
    }

    cout << median(nums, k) * k << '\n';
}