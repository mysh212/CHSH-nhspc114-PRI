// Author : ysh
// 2025/08/02 Sat 17:26:02
#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int main(int ac, char* as[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    registerGen(ac, as, 1);

    int n = atoi(as[1]);
    unsigned long long k = atoll(as[2]);
    int o = (atoi(as[3]) == 1);
    
    if(o) n = rnd.next(1, n);

    cout<<n<<"\n";
    for(int i = 0;i<n;i++) {
        cout<<rnd.next(1ULL, k)<<" \n"[i == n - 1];
    }

    return 0;
}