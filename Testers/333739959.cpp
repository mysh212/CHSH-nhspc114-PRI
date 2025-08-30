// Author : ysh 
// Pre-compiled : 2025/08/13 Wed 11:56:09 
 
#include<bits/stdc++.h> 
# 1 "ccb.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "ccb.cpp"


using namespace std;

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

map<long long, int> mark[2];
vector<int>f;
int m;

void check(long long now, int x, int k) {
    if(x == (6 >> 1)) return mark[k][now]++, void();

    for(int i = 1;i<m + 1;i++) check(now + 1LL * f.at((k * (6 >> 1)) + x) * i, x + 1, k);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    f = vector<int>(6);

    cin>>f>>m;

    for(int i = 0;i<1 + 1;i++) check(0, 0, i);

    int64_t ans = 0;
    for(auto &i : mark[0]) if(mark[1].find(-i.first) != mark[1].end()) ans += 1LL * i.second * mark[1].find(-i.first)->second;

    cout<<(ans);
    return 0;
}
/*  
// Author : ysh
// 2025/08/13 Wed 11:38:38
#include<bits/stdc++.h>
using namespace std;
#define N 6
#include<slow>

map<long long, int> mark[2];
vector<int>f;
int m;

void check(long long now, int x, int k) {
    if(x == (N >> 1)) return mark[k][now]++, void();
    // debug(k, x);
    re(i, 1, m + 1) check(now + 1LL * f.at((k * (N >> 1)) + x) * i, x + 1, k);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    f = vector<int>(N);

    cin>>f>>m;

    re(i, 1 + 1) check(0, 0, i);

    int64_t ans = 0;
    repo(&i, mark[0]) if(mark[1].find(-i.first) != mark[1].end()) ans += 1LL * i.second * mark[1].find(-i.first)->second;

    out(ans);
    return 0;
}  
*/  
