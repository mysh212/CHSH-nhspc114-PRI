// Author : ysh 
// Pre-compiled : 2025/08/14 Thu 13:11:54 
 
#include<bits/stdc++.h> 
# 1 "ccb.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "ccb.cpp"


using namespace std;
# 1 "C:\\Users\\ysh00\\Coding\\library/fast" 1

inline char readchar() {
 const int S = 1<<20;
 static char buf[S], *p = buf, *q = buf;
 if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
 return *p++;
}
bool __flag = 0;
inline int readint() {
 int x = 0, c = readchar(), neg = false;
 __flag = 1;
 while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
 if(c == '-') neg = true, c = readchar();
 while('0' <= c && c <= '9') x = x*10 + (c^'0'), __flag = 0,c = readchar();
 if(neg) x = -x;
 return x;
}
inline long long readll() {
 long long x = 0, c = readchar(), neg = false;
 __flag = 1;
 while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
 if(c == '-') neg = true, c = readchar();
 while('0' <= c && c <= '9') x = x*10 + (c^'0'), __flag = 0,c = readchar();
 if(neg) x = -x;
 return x;
}
inline short readshort() {
 short x = 0, c = readchar(), neg = false;
 __flag = 1;
 while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
 if(c == '-') neg = true, c = readchar();
 while('0' <= c && c <= '9') x = x*10 + (c^'0'), __flag = 0,c = readchar();
 if(neg) x = -x;
 return x;
}
struct __fast_read{
 void tie(int x) {
 }
}__in__;
inline __fast_read& operator>>(__fast_read& in,int &x) {
    x = readint();
    return in;
}
inline __fast_read& operator>>(__fast_read& in,long long &x) {
    x = readll();
    return in;
}
inline __fast_read& operator>>(__fast_read& in,short &x) {
    x = readshort();
    return in;
}
inline __fast_read& operator>>(__fast_read& in,char &x) {
    x = readchar();
    return in;
}
# 5 "ccb.cpp" 2
# 1 "C:\\Users\\ysh00\\Coding\\library/slow" 1
# 27 "C:\\Users\\ysh00\\Coding\\library/slow"
template<class T>
__fast_read& operator>>(__fast_read& fin,vector<T>&f) {
    for(auto &&i : f) fin>>i;
    return fin;
}
template<class T,class R>
__fast_read& operator>>(__fast_read& fin,pair<T,R>&x) {
    fin>>x.first>>x.second;
    return fin;
}
# 49 "C:\\Users\\ysh00\\Coding\\library/slow"
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

struct dsu{
    int64_t t = 0;
    vector<int64_t>color;
    vector<array<int64_t, 4>>rev;

    dsu(int64_t n):
        color(n, -1) {};

    int64_t ff(int64_t x) {
        if(color[x] < 0) return x;
        return ff(color[x]);
    }
    void mg(int64_t a, int64_t b) {
        int64_t l = ff(a);
        int64_t r = ff(b);
        if(l == r) return;
        if(-color[l] > -color[r]) swap(l, r);
        rev.push_back({l, color[l], r, color[r]});
        color[r] += color[l];
        color[l] = r;
        t++;
    }
    void revert(int64_t x) {
        assert(!rev.empty() && x >= 0);
        while(t > x) {
            color[rev.back()[0]] = rev.back()[1];
            color[rev.back()[2]] = rev.back()[3];
            rev.pop_back();
            t--;
        }
        return;
    }
    inline void rollback(int64_t x) {
        return revert(x);
    }
};
signed main() {
    ios::sync_with_stdio(false);
    __in__.tie(0);

    int64_t a,b;__in__>>a>>b;
    vector<vector<pair<int64_t, int64_t>>>f(a);
    vector<array<int64_t, 3>>v;
    for(int64_t _ = 0;_<b;_++) {
        int64_t a,b,c;__in__>>a>>b>>c;
        a--; b--;
        f[a].push_back({b, c});
        f[b].push_back({a, c});
        v.push_back({a, b, c});
    }

    dt:

    vector<int64_t>mk(a, -1);
    priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t,int64_t>>, greater<pair<int64_t,int64_t>>>q;
    int64_t k;__in__>>k;
    int64_t tmp;
    for(int64_t _ = 0;_<k;_++) __in__>>tmp, q.emplace(0LL, tmp - 1);


    while(!q.empty()) {
        auto now = q.top(); q.pop();
        int64_t l, d;
        tie(l, d) = now;

        if(mk[d] != -1) continue;
        mk[d] = l;

        for(auto &i : f[d]) if(mk[i.first] == -1) q.emplace(l + i.second, i.first);
    }

    '*';
    sort:



    sort(v.begin(),v.end(), [&] (array<int64_t, 3>&a, array<int64_t, 3>&b) {
        return (max(mk[a[0]], mk[a[1]])) < (max(mk[b[0]], mk[b[1]]));
    });
    '*';

    '*';
    readq:
    int64_t qq;__in__>>qq;
    vector<array<int64_t, 3>>qu(qq);
    int64_t t = 0;
    for(auto &i : qu) __in__>>i[0]>>i[1], i[0]--, i[1]--, i[2] = t++;

    '*';
    binary:
    vector<int64_t>ans(qq, -1);
    dsu du(a);
    const auto check = [&] (auto && self, vector<array<int64_t, 3>> &f, int64_t l, int64_t r) {
        '*';
        if(f.empty()) return;
        if(l == r) {
            '*';
            for(auto &i : f) ans[i[2]] = l;
            return;
        }

        const int64_t flag = du.t;

        int64_t mid = (l + r) >> 1;


        for(int64_t i = l;i<mid + 1;i++) du.mg(v[i][0], v[i][1]);

        vector<array<int64_t, 3>>ll, rr;

        for(auto &i : f) {
            if(du.ff(i[0]) == du.ff(i[1])) ll.push_back(i);
            else rr.push_back(i);
        }

        self(self, rr, mid + 1, r);
        du.rollback(flag);
        self(self, ll, l, mid);

        return;
    };

    if(b == 0) {
        for(int64_t i = 0;i<qq;i++) cout<<(0)<<"\n";
        return 0;
    }
    '*';
    check(check, qu, 0, v.size() - 1);


    for(int64_t i = 0;i<qq;i++) cout<<((qu[i][0] == qu[i][1] ? mk[qu[i][0]] : (max(mk[v[ans[i]][0]], mk[v[ans[i]][1]]))))<<"\n";

    return 0;
}
/*  
// Author : ysh
// 2025/08/13 Wed 13:49:54
#include<bits/stdc++.h>
using namespace std;
#include<fast>
#include<slow>
#define int int64_t
struct dsu{
    int t = 0;
    vc<int>color;
    vc<array<int, 4>>rev;

    dsu(int n):
        color(n, -1) {};

    int ff(int x) {
        if(color[x] < 0) return x;
        return ff(color[x]);
    }
    void mg(int a, int b) {
        int l = ff(a);
        int r = ff(b);
        if(l == r) return;
        if(-color[l] > -color[r]) swap(l, r);
        rev.push_back({l, color[l], r, color[r]});
        color[r] += color[l];
        color[l] = r;
        t++;
    }
    void revert(int x) {
        assert(!rev.empty() && x >= 0);
        while(t > x) {
            color[rev.back()[0]] = rev.back()[1];
            color[rev.back()[2]] = rev.back()[3];
            rev.pop_back();
            t--;
        }
        return;
    }
    inline void rollback(int x) {
        return revert(x);
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vc<vc<pair<int, int>>>f(a);
    vc<array<int, 3>>v;
    re(b) {
        int a,b,c;cin>>a>>b>>c;
        a--; b--;
        f[a].push_back({b, c});
        f[b].push_back({a, c});
        v.push_back({a, b, c});
    }

    dt:

    vc<int>mk(a, -1);
    priority_queue<pair<int, int>, vc<pair<int,int>>, greater<pair<int,int>>>q;
    int k;cin>>k;
    int tmp;
    re(k) cin>>tmp, q.emplace(0LL, tmp - 1);
    // repo(&i, roots) q.emplace(0LL, i);

    while(!q.empty()) {
        auto now = q.top(); q.pop();
        int l, d;
        tie(l, d) = now;

        if(mk[d] != -1) continue;
        mk[d] = l;

        repo(&i, f[d]) if(mk[i.first] == -1) q.emplace(l + i.second, i.first);
    }

    debug("sort");
    sort:
    #define max_dt(i) (max(mk[i[0]], mk[i[1]]))

    // re(i, a) repo(&j, f[i)) if(i <= j.first) v.push_back({i, j.first, j.second});
    sort(all(v), [&] (array<int, 3>&a, array<int, 3>&b) {
        return max_dt(a) < max_dt(b);
    });
    debug(v);

    debug("readq");
    readq:
    int qq;cin>>qq;
    vc<array<int, 3>>qu(qq);
    int t = 0;
    repo(&i, qu) cin>>i[0]>>i[1], i[0]--, i[1]--, i[2] = t++;

    debug("binary");
    binary:
    vc<int>ans(qq, -1);
    dsu du(a);
    const auto check = [&] (auto && self, vc<array<int, 3>> &f, int l, int r) {
        debug(f, l, r);
        if(f.empty()) return;
        if(l == r) {
            debug(f, l);
            repo(&i, f) ans[i[2]] = l;
            return;
        }

        const int flag = du.t;
        
        int mid = (l + r) >> 1;
        // du = dsu(a);
        // re(i, mid + 1) du.mg(v[i][0], v[i][1]);
        re(i, l, mid + 1) du.mg(v[i][0], v[i][1]);

        vc<array<int, 3>>ll, rr;

        repo(&i, f) {
            if(du.ff(i[0]) == du.ff(i[1])) ll.push_back(i);
            else rr.push_back(i);
        }

        self(self, rr, mid + 1, r);
        du.rollback(flag);
        self(self, ll, l, mid);

        return;
    };

    if(b == 0) {
        re(i, qq) outl(0);
        return 0;
    }
    debug(mk);
    check(check, qu, 0, v.size() - 1);
    // re(i, qq) if(qu[i][0] == qu[i][1]) ans[i] = mk[qu[i][0]];
    // debug('o');
    re(i, qq) outl((qu[i][0] == qu[i][1] ? mk[qu[i][0]] : max_dt(v[ans[i]])));

    return 0;
}  
*/  
