#include<bits/stdc++.h>
#define ll long long
using namespace std;
int N=1e5;
ll l,r;
ll res;
void calc(int n) {
    string s1=to_string(n);
    string s2=s1;
    reverse(s2.begin(),s2.end());
    for (int i=0;i<10;i++) {
        string t=to_string(i);
        string s=s1+t+s2;
        ll num=0;
        for (int j=0;j<s.size();j++) {
            num*=10;
            num+=(ll)s[j]-48;
        }
        if (num>=l&&num<=r) {
            res+=num;
            //cout<<s<<endl;
        }
    }
    string s=s1+s2;
    ll num=0;
    for (int j=0;j<s.size();j++) {
        num*=10;
        num+=(ll)s[j]-48;
    }
    if (num>=l&&num<=r) {
        res+=num;
        //cout<<s<<endl;
    }
}
int main(){
    cin>>l>>r;
    for (ll i=1;i<=9;i++) if(i>=l&&i<=r) res+=i;
    for (int i=1;i<N;i++) {
        calc(i);
    }
    cout<<res;
}
