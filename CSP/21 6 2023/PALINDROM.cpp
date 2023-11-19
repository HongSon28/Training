#include<bits/stdc++.h>
using namespace std;
int n;
long long x,y;
string s;
long long res=1e18;
int main() {
    freopen("PALINDROM.INP","r",stdin);
    freopen("PALINDROM.OUT","w",stdout);
    cin>>n>>x>>y;
    cin>>s;
    s=' '+s;
    for (int k=1;k<=n;k++) {
        long long sum=k*x;
        if (k==n) sum=0;
        string t=s.substr(1,1);
        s.erase(1,1);
        s+=t;
        if (n%2==0) {
            int i=n/2,j=n/2+1;
            while (i>=1&&j<=n) {
                if (s[i]!=s[j]) sum+=y;
                i--;
                j++;
            }
        } else {
            int i=n/2,j=i+2;
            while (i>=1&&j<=n) {
                if (s[i]!=s[j]) sum+=y;
                i--;
                j++;
            }
        }
        res=min(res,sum);
    }
    cout<<res;
}
