#include<bits/stdc++.h>
using namespace std;
string s;
int n,c,start;
long long mul=1;
string a[1001];
char res[1001];
long long x;
int main() {
    //freopen("FINDWORD.INP","r",stdin);
    //freopen("FINDWORD.OUT","w",stdout);
    cin>>s;
    for (int i=0;i<s.size();i++)
        if (s[i]=='#') n++;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        sort(a[i].begin(),a[i].end());
    }
    cin>>x;
    for (int i=n-1;i>=0;i--) {
        if (mul>x/a[i].length()) {
            start=i;
            break;
        }
        mul*=a[i].length();
    }
    for (int i=0;i<start;i++) res[i]=a[i][0];
    mul=1;
    for (int i=n-1;i>=start;i--) mul*=a[i].length();
    for (int i=start;i<n;i++)   {
        //cout<<a[i]<<endl;
        mul/=a[i].length();
        int t=ceil((float)x/(float)mul)-1;
        res[i]=a[i][t];
        x%=mul;
        if (x==0) x=mul;
    }
    for (int i=0;i<s.size();i++) {
        if (s[i]=='#') {
            cout<<res[c];
            c++;
        }
        else cout<<s[i];
    }
}
