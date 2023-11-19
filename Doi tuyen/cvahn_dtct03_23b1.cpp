#include<bits/stdc++.h>
using namespace std;
string n;
int len;
bool used[10];
int res=-1;
bool prime(int n) {
    if (n<=1) return false;
    for (int i=2;i*i<=n;i++)
        if (n%i==0) return false;
    return true;
}
void check() {
    string s;
    for (int i=1;i<=len;i++)
        if (used[i]) s+=n[i];
    if (s.empty()) return;
    int temp=stoi(s);
    if (prime(temp)) res=max(res,temp);
}
void rec(int i) {
    used[i]=false;
    if (i==len) check();
    else rec(i+1);
    used[i]=true;
    if (i==len) check();
    else rec(i+1);
}
int main() {
    cin>>n;
    len=n.size();
    n=' '+n;
    rec(1);
    cout<<res;
}
