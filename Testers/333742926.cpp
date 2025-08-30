// Author : ysh 
// Pre-compiled : 2025/08/13 Wed 12:40:39 
 
#include<bits/stdc++.h> 
#include<bits/extc++.h>
# 1 "ccb.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "ccb.cpp"



using namespace std;
using namespace __gnu_pbds;
constexpr int N = int(1e5) << 1;
constexpr int R = __lg(N) + 1;
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
# 9 "ccb.cpp" 2
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>t;
    int ct = 0;

    int a,b;cin>>a>>b;
    vector<int>f(a);
    cin>>f;

    auto get_mid = [&] () {
        if(b & 1) return ((*t.find_by_order(b >> 1)) >> R) << 1;
        auto found = t.find_by_order(b >> 1);
        return (*prev(found) + *found) >> R;
    };

    int ans = INT_MAX;
    for(int i = 0;i<a;i++) {
        t.insert((1LL * f.at(i) << R) + ++ct);
        if(t.size() < b) continue;
        if(t.size() > b) t.erase(t.lower_bound(1LL * f.at(i - b) << R));

        ans = min(int(get_mid()), ans);
        '*';

    }

    cout<<(fixed);
    cout<<(setprecision(10));
    cout<<((long double) (ans) * b / 2);
    return 0;
}
/*  
// Author : ysh
// 2025/08/13 Wed 12:05:49
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
constexpr int N = int(1e5) << 1;
constexpr int R = __lg(N) + 1;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>t;
    int ct = 0;

    int a,b;cin>>a>>b;
    vc<int>f(a);
    cin>>f;

    auto get_mid = [&] () {
        if(b & 1) return ((*t.find_by_order(b >> 1)) >> R) << 1;
        auto found = t.find_by_order(b >> 1);
        return (*prev(found) + *found) >> R;
    };

    int ans = INT_MAX;
    re(i, a) {
        t.insert((1LL * f.at(i) << R) + ++ct);
        if(t.size() < b) continue;
        if(t.size() > b) t.erase(t.lower_bound(1LL * f.at(i - b) << R));
        
        ans = min(int(get_mid()), ans);
        debug(*t.begin());
        // t.insert(f.at(i));
    }

    out(fixed);
    out(setprecision(10));
    out((long double) (ans) * b / 2);
    return 0;
}  
*/  
