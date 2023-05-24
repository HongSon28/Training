#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--) {
        string s,f,l;
        cin>>s>>f>>l;
        int nf=f.size(),nl=l.size(),ns=s.size();
        string sf=s.substr(ns-nf,nf);
        string sl=s.substr(0,nl);
        //cout<<sf<<' '<<sl<<endl;
        if (sf==f&&sl==l) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
