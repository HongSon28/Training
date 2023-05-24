#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("DEMXAU.INP","r",stdin);
    freopen("DEMXAU.OUT","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    long long x,cnt=0,res=0;
    cin>>x;
    bool a=false,b=false;
    if (s[0]=='b') b=true;
    if (s[n-1]=='a') a=true;
    for (int i=0;i<n-1;i++) {
        if (s[i]=='a'&&s[i+1]=='b') cnt++;
    }
    res=cnt*x;
    if (a==true&&b==true) {
        res+=x-1;
    }
    cout<<res;
}
