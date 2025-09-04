// Author : ysh 
// Pre-compiled : 2025/09/03 Wed 10:26:47 
 
#include<bits/stdc++.h> 
# 1 "ccb.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "ccb.cpp"


using namespace std;
# 1 "C:\\Users\\ysh00\\Coding\\library/tree" 1
template<typename T>
struct tree{
    std::vector<T>f;
    int n;

    tree(int n) {
        this->n = n;
        f.resize(n);
    }

    tree(std::vector<T>&v):
    tree(v.size()) {
        int t = 0;
        for(T i : v) add(t++,i);
    }

    void add(int a,T b) {
        for(;a < n;a = a | (a + 1)) {
            f[a] += b;
        }
    }

    T sum(int a) {
        T ans = 0;
        for(;a >= 0;a = (a & (a + 1)) - 1) {
            ans = ans + f[a];
        }
        return ans;
    }

    T sum(int a,int b) {
        if(a > b) std::swap(a,b);
        assert(!(b >= n || a < 0));
        return sum((std::min(n - 1,b))) - sum(a - 1);
    }
};
# 5 "ccb.cpp" 2
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
# 6 "ccb.cpp" 2
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    map<pair<int, int>, int>m;
    for(int i = 0;i<n;i++) {
        int a,b;cin>>a>>b;
        m.insert({{a, b}, i});
    }

    int r;cin>>r;
    vector<pair<int, int>>f(r);
    for(auto &i : f) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        i = {m.find({a, b})->second, m.find({c, d})->second};
    }

    int ans = 0;
    tree<int>t(n);

    for(auto &i : f) if(i.first > i.second) swap(i.first, i.second);
    sort(f.begin(),f.end());

    for(auto &i : f) {
        ans += t.sum(i.first, i.second);
        t.add(i.second, 1);
    }

    cout<<(ans);
    return 0;
}
/*  
// Author : ysh
// 2025/09/03 Wed 09:57:58
#include<bits/stdc++.h>
using namespace std;
#include<tree>
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    map<pair<int, int>, int>m;
    re(i, n) {
        int a,b;cin>>a>>b;
        m.insert({{a, b}, i});
    }

    int r;cin>>r;
    vc<pair<int, int>>f(r);
    repo(&i, f) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        i = {m.find({a, b})->second, m.find({c, d})->second};
    }

    int ans = 0;
    tree<int>t(n);
    
    repo(&i, f) if(i.first > i.second) swap(i.first, i.second);
    sort(all(f));

    repo(&i, f) {
        ans += t.sum(i.first, i.second);
        t.add(i.second, 1);
    }

    out(ans);
    return 0;
}  
*/  
