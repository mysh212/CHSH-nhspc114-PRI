// Author : ysh
// 2025/08/29 Fri 00:22:35
#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int main(int ac, char* as[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    registerGen(ac, as, 1);

    int n = atoi(as[1]);
    int k = atoi(as[2]);
    bool o = (atoi(as[3]) == 1);

    if(o) n = rnd.next(0, n);

    cout<<n<<"\n";
    for(int i = 0;i<n;i++) {
        cout<<rnd.next(1, k)<<" "<<rnd.next(1, k)<<"\n";
    }

    return 0;
}