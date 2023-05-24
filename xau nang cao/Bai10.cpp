#include<bits/stdc++.h>
using namespace std;
int cnt1[123]={};
int cnt2[123]={};
bool comp() {
    for (int i=65;i<=122;i++) {
        if (cnt1[i]!=cnt2[i])
            return false;
    }
    return true;
}
int main() {
    int n,m;
    int res=0;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    for (int i=0;i<n;i++) {
        cnt1[a[i]]++;
        cnt2[b[i]]++;
    }
    if (comp()==true)
        res++;
    for (int i=n;i<m;i++) {
        cnt2[b[i-n]]--;
        cnt2[b[i]]++;
        if (comp()==true)
            res++;
    }
    cout<<res;
}
