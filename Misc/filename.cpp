#include<bits/stdc++.h>
using namespace std;
int n,cnt,l=1,r=1;
string s;
signed main(){
    cin>>n>>s;
    s=' '+s;
    while(l<=r && r<=n){
        while(l<=n&&s[l]!='x'){
            l++;
            r=l;
        }
        if (l>n) break;
        while(r+1<=n&&s[r+1]=='x') r++;
        cnt+=max(0,r-l-1);
        l=r+1;
        r=l;
    }
    cout<<cnt;
}