// Author : ysh
// 2025/08/02 Sat 18:19:02
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);

    int last = 0;
    for(int &i : f) cin>>i, i = last ^= i;

    int ans = 0;
    for(int i = -1;i<n;i++) {
        for(int j = i + 1;j<n;j++) {
            // cerr<<i<<" "<<j<<"\n";
            int left = (i == -1 ? 0 : f.at(i));
            int right = f.at(j);
            
            ans = max(ans, right ^ left);
        }
    }

    cout<<ans;
    return 0;
}