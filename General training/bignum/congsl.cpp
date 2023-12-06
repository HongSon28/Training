#include<bits/stdc++.h>
using namespace std;
string operator + (string a, string b) {
    string res;
    while (a.length()>b.length())
        b='0'+b;
    while (a.length()<b.length())
        a='0'+a;
    int rem=0;
    for (int i=a.length()-1;i>=0;i--) {
        int t=(a[i]-48)+(b[i]-48)+rem;
        rem=t/10;
        t=t%10;
        res=char(t+48)+res;
    }
    if (rem!=0) {
        res=char(rem+48)+res;
    }
    return res;
}
int main() {
    string a,b;
    cin>>a>>b;
    cout<<a+b;
}
