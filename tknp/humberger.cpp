#include<bits/stdc++.h>
using namespace std;
long long cb=0,cs=0,cc=0;
long long nb,ns,nc;
long long pb,ps,pc;
long long r;
bool check(long long n) {
    long long rb=n*cb-nb, rs=n*cs-ns, rc=n*cc-nc;
    long long rq=0;
    if (rb>0) rq+=rb*pb;
    if (rc>0) rq+=rc*pc;
    if (rs>0) rq+=rs*ps;
    if (rq<=r) return true;
    return false;
}
int main() {
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='B') cb++;
        else if (s[i]=='S') cs++;
        else cc++;
    }
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    cin>>r;
    long long lo=0,hi=r+nb+ns+nc;
    while (lo<hi) {
        long long mid=lo+(hi-lo+1)/2;
        if (check(mid)==true) lo=mid;
        else hi=mid-1;
    }
    cout<<lo;
}

