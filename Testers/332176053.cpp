// Author : ysh
// 2025/08/02 Sat 18:53:33
#include<bits/stdc++.h>
using namespace std;
struct node {
    node* bit[2];
    
    explicit node() {
        bit[0] = bit[1] = nullptr;
    }
};
struct tree {
    node* root = nullptr;

    tree():
        root(new node()) {};

    void insert(uint64_t x) {
        node* now = root;
        for(uint64_t mask = (1ULL << 63); mask > 0; mask = mask >> 1) {
            bool p = ((x & mask) != 0);
            if(!now -> bit[p]) now -> bit[p] = new node();
            now = now -> bit[p];
        }
        return;
    }

    uint64_t satisfy(uint64_t x) {
        node* now = root;
        x = ~x;
        uint64_t ans = 0;
        for(uint64_t mask = (1ULL << 63); mask > 0; mask = mask >> 1) {
            bool p = ((x & mask) != 0);
            // cerr<<boolalpha<<p<<"\n";
            if(now -> bit[p]) now = now -> bit[p], (p ? ans = ans | mask : 0);
            else now = now -> bit[!p], (!p ? ans = ans | mask : 0);
        }
        return ans;
    }
};
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    tree t = tree();
    t.insert(0ULL);

    int n;cin>>n;
    uint64_t f[n] = {};
    uint64_t last = 0;
    for(int i = 0;i<n;i++) cin>>f[i], f[i] = last ^= f[i], t.insert(f[i]);

    uint64_t ans = 0;
    for(int i = 0;i<n;i++) ans = max(ans, f[i] ^ t.satisfy(f[i]));

    cout<<ans;
    return 0;
}