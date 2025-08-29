// Author : ysh
// 2025/08/25 Mon 18:51:24
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
    
    // m = min({1LL * m, max(0LL, (1LL * n * (n - 1)) >> 1), int64_t(1e6), 1LL * root * (n - root)});
    m = n - 1;
    int root = m >> 1;

    cout<<n<<" "<<m<<"\n";

    vector<int>mark(n);
    iota(mark.begin(), mark.end(), 1);
    shuffle(mark.begin(), mark.end());

    for(int i = 1;i<=root;i++) {
        cout<<mark.at(i - 1)<<" "<<mark.at(i)<<"\n";
    }

    int nroot = root >> 2;
    for(int i = root + 1;i<n;i++) {
        cout<<mark.at(i)<<" "<<mark.at(rnd.next(0, nroot))<<"\n";
    }

    for(int i = 0;i<n;i++) cout<<rnd.next(0, y)<<" \n"[i == n - 1];
    return 0;
}