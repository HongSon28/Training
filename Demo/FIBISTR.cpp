#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6;
ll dp[N+5];
pair<string,string>p[N+5];
ll mod=1234567890;
int n;
string s,a,b;
int main() {
    p[1].first="A",p[1].second="A";
    p[2].first="B",p[2].second="B";
    while (cin>>n>>s) {
        int l=s.length();
        if (l==1) {
            if (s=="A") dp[1]=1;
            else if (s=="B") dp[2]=1;
        }
        for (int i=3;i<=n;i++) {
            dp[i]=(dp[i-1]+dp[i-2])%mod;
            if (l-1>=p[i-1].first.length())
                a=p[i-1].first;
            else
                a=p[i-1].first.substr(0,l-1);
            if (l-1>=p[i-1].second.length())
                b=p[i-1].second;
            else
                b=p[i-1].second.substr(p[i-1].second.length()-l,l-1);
            string t=b+a;
            if (t.find(s)<t.size()) dp[i]++;
        }
    }
}
