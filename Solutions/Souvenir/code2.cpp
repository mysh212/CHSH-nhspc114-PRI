// Author : ysh
// 2025/08/29 Fri 00:16:53
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        #define f envelopes
        sort(f.begin(), f.end());
        
        vector<pair<int, vector<int>>>v;
        for(auto &i : f) {
            if(v.empty() || v.back().first != i[0]) v.push_back({i[0], {i[1]}});
            else v.back().second.push_back(i[1]);
        }

        vector<int>mark;
        vector<pair<int, int>>rollback;
        for(auto &i : v) {
            rollback.clear();
            int now = i.first;
            for(int &j : i.second) {
                auto found = lower_bound(mark.begin(), mark.end(), j);
                if(found == mark.end()) rollback.push_back({mark.size(), j});
                else rollback.push_back({found - mark.begin(), j});
            }
            bool o = 0;
            int n = mark.size();
            for(auto &k : rollback) {
                int i, j;
                tie(i, j) = k;
                if(i == n) {
                    if(!o) {
                        mark.push_back(j);
                        o = 1;
                        continue;
                    }
                    mark.back() = min(j, mark.back());
                    continue;
                }
                mark.at(i) = min(j, mark.at(i));
            }
        }

        return mark.size();
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(n, vector<int>(2));
    for(auto &i : f) for(int &j : i) cin>>j;
    cout<<Solution().maxEnvelopes(f);
    return 0;
}