#include<bits/stdc++.h>
using namespace std;
const int N=100;
string s[N+5];
int n,d,res,len;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>d;
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=0;i<d;i++) {
        bool check=true;
        for (int j=1;j<=n;j++) {
            if (s[j][i]=='o') continue;
            check=false;
            break;
        }
        if (!check) len=0;
        else len++;
        res=max(res,len);
    }
    cout<<res;
}
