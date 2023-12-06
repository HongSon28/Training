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
        int t=(a[i]+48)-(b[i]+48)-rem;
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
    return res;
}
vector <string> res;
int main() {
    string n;
    cin>>n;
    string fi[10001];
    fi[1]="1";
    fi[2]="1";
    int cnt=2;
    for (int i=3;i<=10001;i++) {
        fi[i]=fi[i-1]+fi[i-2];
        cnt++;
        if (comp(fi[i],n)>=0)
            break;
    }
    string m=n;
    while (n!="0") {
        while (comp(n,fi[cnt])==-1||fi[cnt]==m)
            cnt--;
        n=n-fi[cnt];
        res.push_back(fi[cnt]);
    }
    for (int i=res.size()-1;i>=0;i--)
        cout<<res[i]<<" ";
}
