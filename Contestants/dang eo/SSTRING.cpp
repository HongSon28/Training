#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
    freopen("SSTRING.INP","r",stdin);
    freopen("SSTRING.OUT","w",stdout);
    cin>>s;
    n=s.size();
    s=' '+s;
    int l=0,r=0;
    for(int i=1;i<=s.size()-1;i++){
        if(s[i]==s[s.size()-1]){
            l=i;
            break;
        }
    }
    for(int i=s.size()-1;i>=1;i--){
        if(s[i]==s[1]){
            r=i;
            break;
        }
    }
    if(r>n-l+1) cout<<1<<' '<<r-1<<' '<<2<<' '<<r;
    else cout<<l<<' '<<n-1<<' '<<l+1<<' '<<n;
}
