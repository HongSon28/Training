#include<bits/stdc++.h>
using namespace std;
string s;
long long sum;
int main() {
    freopen("HOANVISO.INP","r",stdin);
    freopen("HOANVISO.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    sort(s.begin(),s.end());
    for (auto i:s) sum+=i-'0';
    if (sum%3!=0||s[0]!='0') cout<<-1;
    else {
        reverse(s.begin(),s.end());
        cout<<s;
    }
}
