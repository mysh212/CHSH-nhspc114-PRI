// Author : ysh 
// Pre-compiled : 2025/08/13 Wed 11:32:04 
 
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
# 5 "ccb.cpp" 2
int check(int x) {
    int ans = 0;
    for(int i = 0;i<x + 1;i++) ans = ans + int(sqrt(i));
    return ans;
}
const int R = int(1e9) + 7;
int fp(int a, int b) {
    if(b == 0) return 1;

    int now = fp(a, b >> 1);
    now = 1LL * now * now % R;

    if(b & 1) return 1LL * now * a % R;
    else return now;
}
int inv(int x) {
    return fp(x, R - 2);
}
int main() {



    long long n;cin>>n;
    n = n % R;
    int sig = (((1LL * n * (n + 1) % R) * (((1LL * n) << 1) + 1) % R) * inv(6) % R) - n;

    int up = (1LL * n * n % R) * n % R;
    int ans = (((up - sig) % R) + R) % R;
    '*';

    cout<<(ans);
    return 0;
}
/*  
// Author : ysh
// 2025/08/13 Wed 11:08:08
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int check(int x) {
    int ans = 0;
    re(i, x + 1) ans = ans + int(sqrt(i));
    return ans;
}
const int R = int(1e9) + 7;
int fp(int a, int b) {
    if(b == 0) return 1;

    int now = fp(a, b >> 1);
    now = 1LL * now * now % R;

    if(b & 1) return 1LL * now * a % R;
    else return now;
}
int inv(int x) {
    return fp(x, R - 2);
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    long long n;cin>>n;
    n = n % R;
    int sig = (((1LL * n * (n + 1) % R) * (((1LL * n) << 1) + 1) % R) * inv(6) % R) - n;
    
    int up = (1LL * n * n % R) * n % R;
    int ans = (((up - sig) % R) + R) % R;
    debug(sig, up, (inv(6) * 6) % R);

    out(ans);
    return 0;
}  
*/  
