#include<bits/stdc++.h>
using namespace std;
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
string operator - (string a, string b) {
    string res;
    if (a==b)
        return "0";
    while (a.length()>b.length())
        b='0'+b;
    while (a.length()<b.length())
        a='0'+a;
    int rem=0;
    for (int i=a.length()-1;i>=0;i--) {
        int t=(a[i]-48)-(b[i]-48)-rem;
        if (t<0) {
            rem=1;
            t+=10;
        } else {
            rem=0;
        }
        res=char(t+48)+res;
    }
    while (res[0]=='0')
        res.erase(0,1);
    if (res.empty()) res='0';
    return res;
}
string operator / (string a, long long b) {
    string res;
    long long t=0;
    for (auto k:a) {
        t=t*10+(k-48);
        long long x=t/b;
        t=t%b;
        res=res+char(x+48);
    }
    while (res[0]=='0')
        res.erase(0,1);
    if (res.empty()==true) {
        res='0';
    }
    return res;
}
int main() {
    string a,b;
    cin>>a>>b;
    string c=a+b;
    string s1=c/2;
    string s2=a-s1;
    cout<<s1<<endl<<s2;
}

