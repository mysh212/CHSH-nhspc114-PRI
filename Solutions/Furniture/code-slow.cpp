// Author : ysh
// 2025/08/25 Mon 12:04:38
#include<bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n, m;cin>>n>>m;
    vector<vector<int>>f(n);
    vector<int>in(n);
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        a--; b--;
        f.at(a).push_back(b);
        in.at(b)++;
    }

    queue<int>q;
    vector<int>mark;
    for(int i = 0;i<n;i++) if(in.at(i) == 0) q.push(i);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        mark.push_back(now);
        for(int &i : f.at(now)) if(--in.at(i) == 0) q.push(i);
    }

    vector<int>mk(n);
    for(int &i : mk) cin>>i;

    vector<long long>ans(n);
    int now = 0;
    for(int &i : mark) for(int &j : f.at(i)) ans.at(j) = max(ans.at(j), ans.at(i) + mk.at(i));

    for(long long &i : ans) cout<<i<<" ";
    return 0;
}