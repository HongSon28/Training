#include<bits/stdc++.h>
using namespace std;
bool check(string s) {
    int n=s.size();
    for (int i=0;i<n;i++) {
        //cout<<s[i]<<' '<<s[n-1-1]<<endl;
        if (s[i]!=s[n-1-i]) return false;
    }
    return true;
}
int main() {
    string s;
    cin>>s;
    int mx=0;
    int n=s.size();
    for (int i=n-1;i>=0;i--) {
        string temp=s.substr(i,n-1-i+1);
        if (check(temp)==true) mx=max(mx,n-1-i+1);
    }
    int res=n-mx;
    cout<<res<<endl;
    for (int i=res-1;i>=0;i--) s+=s[i];
    cout<<s;
}
