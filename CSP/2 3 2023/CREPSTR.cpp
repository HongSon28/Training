#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--) {
        string a,b;
        cin>>a>>b;
        int c=__gcd(a.size(),b.size());
        string s=a.substr(0,c);
        string ca,cb;
        for (int i=0;i<a.size()/c;i++) ca+=s;
        for (int i=0;i<b.size()/c;i++) cb+=s;
        if (ca==a&&cb==b) cout<<s<<endl;
        else cout<<"!"<<endl;
    }
}
