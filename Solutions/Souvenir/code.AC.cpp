// Author : ysh
// 2025/08/29 Fri 00:33:12
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int, int>>f(n);
    for(auto &i : f) cin>>i.first>>i.second;

    sort(f.begin(), f.end());

    vector<pair<int, vector<int>>>v;
    for(auto &i : f) {
        if(v.empty() || v.back().first != i.first) v.push_back({i.first, {i.second}});
        else v.back().second.push_back(i.second);
    }

    vector<int>mark;
    for(auto &i : v) {
        vector<pair<int, int>>mk;
        for(int &j : i.second) {
            auto found = lower_bound(mark.begin(), mark.end(), j);
            mk.push_back({found - mark.begin(), j});
        }

        bool o = 0;
        int n = mark.size();
        for(auto &j : mk) {
            if(j.first == n) {
                if(!o) mark.push_back(j.second), o = 1;
                else mark.back() = min(j.second, mark.back());
                continue;
            }
            mark.at(j.first) = min(j.second, mark.at(j.first));
        }
    }

    cout<<mark.size();
    return 0;
}