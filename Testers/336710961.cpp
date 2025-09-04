// Author : ysh 
// Pre-compiled : 2025/09/03 Wed 13:47:31 
 
#include<bits/stdc++.h>
#include<bits/extc++.h>
# 1 "ccb.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "ccb.cpp"



using namespace std;
using namespace __gnu_pbds;
# 1 "C:\\Users\\ysh00\\Coding\\library/slow" 1
# 38 "C:\\Users\\ysh00\\Coding\\library/slow"
template<class T>
std::istream& operator>>(std::istream& fin,std::vector<T>&f) {
    for(auto &&i : f) fin>>i;
    return fin;
}
template<class T,class R>
std::istream& operator>>(std::istream& fin,std::pair<T,R>&x) {
    fin>>x.first>>x.second;
    return fin;
}

template<class T>
std::ostream& operator<<(std::ostream& fout,std::vector<T>&f) {
    for(auto &i : f) fout<<i<<" ";
    return fout;
}
template<class T,class R>
std::ostream& operator<<(std::ostream& fout,std::pair<T,R>&x) {
    fout<<x.first<<" "<<x.second;
    return fout;
}
# 7 "ccb.cpp" 2
constexpr int N = int(1e5);
constexpr int R = __lg(N) + 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    tree<int64_t, null_type, less<int64_t>, rb_tree_tag, tree_order_statistics_node_update> t;

    int64_t n;cin>>n;
    map<pair<int64_t, int64_t>, int64_t>m;

    for(int64_t i = 0;i<n;i++) {
        int64_t a,b;cin>>a>>b;
        m.insert({{a, b}, i});
    }

    int64_t r;cin>>r;
    vector<pair<int64_t,int64_t>>f(r);
    for(auto &i : f) {
        int64_t a,b,c,d;cin>>a>>b>>c>>d;
        i = {m.find({a, b}) -> second, m.find({c, d}) -> second};
    }

    int64_t ans = 0;
    int64_t ct = 0;
    for(auto &i : f) if(i.first > i.second) swap(i.first, i.second);
    sort(f.begin(),f.end());
    for(auto &i : f) {
        if(t.lower_bound((i.second + 1) << R) == t.end()) ans += t.size() - t.order_of_key(*t.lower_bound(i.first << R));
        else ans += t.order_of_key(*t.lower_bound((i.second + 1) << R)) - t.order_of_key(*t.lower_bound(i.first << R));
        t.insert((i.second << R) + ++ct);
    }

    cout<<(ans);
    return 0;
}
/*  
// Author : ysh
// 2025/09/03 Wed 10:28:51
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#include<slow>
constexpr int N = int(1e5);
constexpr int R = __lg(N) + 1;
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t;

    int n;cin>>n;
    map<pair<int, int>, int>m;

    re(i, n) {
        int a,b;cin>>a>>b;
        m.insert({{a, b}, i});
    }

    int r;cin>>r;
    vc<pair<int,int>>f(r);
    repo(&i, f) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        i = {m.find({a, b}) -> second, m.find({c, d}) -> second};
    }

    int ans = 0;
    int ct = 0;
    repo(&i, f) if(i.first > i.second) swap(i.first, i.second);
    sort(all(f));
    repo(&i, f) {
        if(t.lower_bound((i.second + 1) << R) == t.end()) ans += t.size() - t.order_of_key(*t.lower_bound(i.first << R));
        else ans += t.order_of_key(*t.lower_bound((i.second + 1) << R)) - t.order_of_key(*t.lower_bound(i.first << R));
        t.insert((i.second << R) + ++ct);
    }

    out(ans);
    return 0;
}  
*/  
