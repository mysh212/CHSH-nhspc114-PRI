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

    double mid = 1e9;
    for (int i = 0; i + k <= n; i++) {
        vector<int> sub;
        sub.insert(sub.begin(), nums.begin() + i, nums.begin() + i + k);
        sort(sub.begin(), sub.end());
        mid = min((sub[k / 2] + sub[(k - 1) / 2]) / 2.00, mid);
    }
    cout << fixed << setprecision(10) << mid * k << '\n';
}