#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
string a,b;
int res[N+5];
int rem;
string calc(string a,string b) {
    string s;
    for (int i=a.size()-1;i>=0;i--) {
        int x,y;
        if (a[i]>='A'&&a[i]<='F') x=(int)a[i]-'A'+10;
        else x=a[i]-'0';
        if (b[i]>='A'&&b[i]<='F') y=(int)b[i]-'A'+10;
        else y=b[i]-'0';
        if (x-y-rem>=0) {
            res[i]=x-y-rem;
            rem=0;
        }
        else {
            res[i]=x-y-rem+16;
            rem=1;
        }
    }
    for (int i=0;i<a.size();i++) {
        if (res[i]==0) s+='0';
        else if (res[i]==1) s+='1';
        else if (res[i]==2) s+='2';
        else if (res[i]==3) s+='3';
        else if (res[i]==4) s+='4';
        else if (res[i]==5) s+='5';
        else if (res[i]==6) s+='6';
        else if (res[i]==7) s+='7';
        else if (res[i]==8) s+='8';
        else if (res[i]==9) s+='9';
        else if (res[i]==10) s+='A';
        else if (res[i]==11) s+='B';
        else if (res[i]==12) s+='C';
        else if (res[i]==13) s+='D';
        else if (res[i]==14) s+='E';
        else if (res[i]==15) s+='F';
    }
    while (s[0]=='0') s.erase(0,1);
    if (s.size()==0) s="0";
    return s;
}
int comp(string x,string y) {
    for (int i=0;i<x.size();i++) {
        int x,y;
        if (a[i]>='A'&&a[i]<='F') x=(int)a[i]-'A'+10;
        else x=a[i]-'0';
        if (b[i]>='A'&&b[i]<='F') y=(int)b[i]-'A'+10;
        else y=b[i]-'0';
        if (x>y) return 1;
        else if (x<y) return -1;
    }
    return 0;
}
int main() {
    cin>>a>>b;
    while (a.size()>b.size()) b='0'+b;
    while (a.size()<b.size()) a='0'+a;
    if (comp(a,b)>=0) cout<<calc(a,b);
    else cout<<'-'<<calc(b,a);
}
