#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("CH9.INP","r",stdin);
    freopen("CH9.OUT","w",stdout);
    cin>>t;
    while (t--) {
        cin>>s;
        int sum=0;
        for (auto i:s) sum+=i-'0';
        sum%=9;
        if (sum==0) sum=9;
        bool flag=false;
        for (int i=0;i<s.size();i++) {
            if (s[i]-'0'>=sum) {
                s[i]-=sum;
                flag=true;
                break;
            }
        }
        if (!flag) {
            sum=9-sum;
            for (int i=s.size()-1;i>=0;i--) {
                if (s[i]-'0'+sum<=9) {
                    s[i]+=sum;
                    break;
                }
            }
        }
        cout<<s<<'\n';
    }
}
