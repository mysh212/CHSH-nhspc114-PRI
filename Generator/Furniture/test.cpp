// Author : ysh
// 2025/08/25 Mon 17:37:01
#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int main(int ac, char* as[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    registerGen(ac, as, 1);

    int n = atoi(as[1]);
    int m = atoi(as[2]);
    int y = atoi(as[3]);
    bool o = (atoi(as[4]) == 1);

    if(o) {
        n = rnd.next(0, n);
        m = rnd.next(0, m);
    }
    
    int root = rnd.next(1, max(1, n >> 7) + 1);
    
    m = min({1LL * m, max(0LL, (1LL * n * (n - 1)) >> 1), int64_t(1e6), 1LL * root * (n - root)});
    
    cout<<n<<" "<<m<<"\n";
    
    vector<int>order(n);
    iota(order.begin(), order.end(), 1);
    shuffle(order.begin(), order.end());
    set<int>roots(order.begin(), order.begin() + root);

    set<pair<int, int>>ans;
    // for(int i : order) cerr<<i<<" ";
    // cerr<<root<<"\n";
    for(int i = 0;i<m;i++) {
        int l, r;
        l = rnd.next(0, n - 2);
        r = rnd.next(max(root, l + 1), n - 1);
        if(ans.find({l, r}) != ans.end()) {
            i--;
            continue;
        }
        cout<<order.at(l)<<" "<<order.at(r)<<"\n";
        ans.insert({l, r});
    }

    for(int i = 0;i<n;i++) cout<<rnd.next(0, y)<<" \n"[i == n - 1];

    return 0;
}