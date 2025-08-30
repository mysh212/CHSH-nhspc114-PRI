// Author : ysh 
// Pre-compiled : 2025/08/02 Sat 17:52:25 
 
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

int main() {



    int n;cin>>n;
    vector<long long>f(n);
    cin>>f;

    vector<long long>mark(63);
    for(auto &i : f) {
        for(int j = 63 - 1; j >= 0; j--) {
            if(!(i & (1LL << j))) continue;
            if(mark.at(j) == 0) {
                mark.at(j) = i;
                break;
            } else {
                i ^= mark.at(j);
            }
        }
    }

    long long ans = 0;
    for(int i = 63 - 1; i >= 0; i--) {
        if(ans & (1LL << i)) continue;
        ans = ans ^ mark.at(i);
    }

    cout<<(ans);
    return 0;
}
/*  
// Author : ysh
// 2025/08/01 Fri 23:26:14
// https://www.luogu.com.cn/problem/P3812
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define R 63
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;cin>>n;
    vc<long long>f(n);
    cin>>f;

    vc<long long>mark(R);
    repo(&i, f) {
        for(int j = R - 1; j >= 0; j--) {
            if(!(i & (1LL << j))) continue;
            if(mark.at(j) == 0) {
                mark.at(j) = i;
                break;
            } else {
                i ^= mark.at(j);
            }
        }
    }

    long long ans = 0;
    for(int i = R - 1; i >= 0; i--) {
        if(ans & (1LL << i)) continue;
        ans = ans ^ mark.at(i);
    }

    out(ans);
    return 0;
}  
*/  
