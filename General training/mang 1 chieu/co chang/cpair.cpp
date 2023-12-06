#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,s;
    cin>>n>>s;
    int a[n];
    int c[2001]={};
    for (int i=0;i<n;i++) {
        cin>>a[i];
        c[a[i]]++;
    }
    int res=0;
    for (int i=1;i<s;i++) {
        if (i!=s-i)
            res+=c[i]*c[s-i];
        else
            res+=c[i]*(c[i]-1);
    }
    cout<<res/2;
}
