#include<bits/stdc++.h>
using namespace std;
string a,b;
int comp (string a, string b) {
    if (a.length()>b.length())
        return 1;
    if (a.length()<b.length())
        return -1;
    for (int i=0;i<a.length();i++) {
        if (a[i]>b[i]) {
            return 1;
        } else if (a[i]<b[i]) {
            return -1;
        }
    }
    return 0;
}
int main() {
    freopen("COMPARE.INP","r",stdin);
    freopen("COMPARE.OUT","w",stdout);
    cin>>a>>b;
    if (comp(a,b)==0) cout<<'=';
    else if (comp(a,b)==1) cout<<'>';
    else cout<<'<';
}
