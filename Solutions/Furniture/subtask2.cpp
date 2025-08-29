// Author : ysh
// 2025/08/25 Mon 18:31:54
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    vector<int>to(a);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        to.at(b)++;
    }

    vector<int>t(a);
    for(int &i : t) cin>>i;

    vector<long long>ans(a);
    function<void(int,long long)> check = [&] (int x, long long now) {
        ans.at(x) = max(ans.at(x), now);

        now += t.at(x);
        for(int &i : f.at(x)) {
            check(i, now);
        }

        return;
    };

    for(int i = 0;i<a;i++) if(to.at(i) == 0) check(i, 0);

    for(long long &i : ans) cout<<i<<" ";
    return 0;
}