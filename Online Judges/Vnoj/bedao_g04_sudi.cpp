#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+5];
long long res;
int lmin[N+5],rmin[N+5],lmax[N+5],rmax[N+5];
stack<int>s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        while (!s.empty()&&a[s.top()]<=a[i]) s.pop();
        if (s.empty()) lmax[i]=1;
        else lmax[i]=s.top()+1;
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i=n;i>=1;i--) {
        while (!s.empty()&&a[s.top()]<a[i]) s.pop();
        if (s.empty()) rmax[i]=n;
        else rmax[i]=s.top()-1;
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i=1;i<=n;i++) {
        while (!s.empty()&&a[s.top()]>=a[i]) s.pop();
        if (s.empty()) lmin[i]=1;
        else lmin[i]=s.top()+1;
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i=n;i>=1;i--) {
        while (!s.empty()&&a[s.top()]>a[i]) s.pop();
        if (s.empty()) rmin[i]=n;
        else rmin[i]=s.top()-1;
        s.push(i);
    }
    for (int i=1;i<=n;i++) {
        //cout<<lmax[i]<<' '<<rmax[i]<<' '<<lmin[i]<<' '<<rmin[i]<<endl;
        res+=a[i]*(i-lmax[i]+1)*(rmax[i]-i+1);
        res-=a[i]*(i-lmin[i]+1)*(rmin[i]-i+1);
    }
    cout<<res;
}
