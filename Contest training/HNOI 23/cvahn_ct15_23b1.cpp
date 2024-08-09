#include<bits/stdc++.h>
using namespace std;
string s;
int res=-1;
void check(string t) {
    if (t.empty()) return;
    int temp=stoi(t);
    if (temp<=1) return;
    for (int i=2;i*i<=temp;i++)
        if (temp%i==0) return;
    res=max(res,temp);
}
void rec(int k,string cur) {
    if (k<s.size()) {
        rec(k+1,cur);
        rec(k+1,cur+s[k]);
    } else check(cur);
}
int main() {
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);
    cin>>s;
    rec(0,"");
    cout<<res;
}
